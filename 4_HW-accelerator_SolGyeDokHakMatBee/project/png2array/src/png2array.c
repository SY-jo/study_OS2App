#include "png2array.h"


sImage_size Get_image_size(FILE* hImage)
{
	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL)
	{
		fprintf(stderr, "png2array: out of memory allocating png_struct\n");
		exit(1);
	}

	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL)
	{
		fprintf(stderr, "png2array: out of memory allocating png_info\n");
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		exit(1);
	}

	png_init_io(png_ptr, hImage);
	png_read_info(png_ptr, info_ptr);


	sImage_size size;
	size.width = png_get_image_width(png_ptr, info_ptr);
	size.height = png_get_image_height(png_ptr, info_ptr);
	size.nChannel = png_get_channels(png_ptr, info_ptr);

	png_destroy_info_struct(png_ptr, &info_ptr);
	png_destroy_read_struct(&png_ptr, NULL, NULL);

	return size;
}


sArrayImage png2array(FILE* hImage)
{
	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL)
	{
		fprintf(stderr, "png2array: out of memory allocating png_struct\n");
		exit(1);
	}

	png_infop info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL)
	{
		fprintf(stderr, "png2array: out of memory allocating png_info\n");
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		exit(1);
	}

	png_init_io(png_ptr, hImage);
	png_read_info(png_ptr, info_ptr);


	//헤더로부터 메타데이터 파싱
	png_uint_32 width, height;
	int bit_depth, color_type, interlace_method, compression_method, filter_method;
	png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type, &interlace_method,
		&compression_method, &filter_method);

	// Color type 에 따른 channel 개수. 
	// 지원되지 않는 타입이 들어왔을 때 freeing 과정으로 넘어가고 error 처리하도록 수정필요
	png_byte nChannel = png_get_channels(png_ptr, info_ptr);
	

	//변환 과정이 row-by-row 로 수행됨. 1개 row 정보를 담는 buffer 가 필요
	png_bytep row = NULL;
	row = png_malloc(png_ptr, png_get_rowbytes(png_ptr, info_ptr));

	//변환 결과를 저장할 array 동적할당
	unsigned int*** pixel_ptr = (unsigned int***)malloc(sizeof(unsigned int**) * nChannel);
	for (int c = 0; c < nChannel; c++)
	{
		pixel_ptr[c] = (unsigned int**)malloc(sizeof(unsigned int*) * height);
		for (int h = 0; h < height; h++)
			pixel_ptr[c][h] = (unsigned int*)malloc(sizeof(unsigned int) * width);
	}

	sArrayImage arrayImage;
	arrayImage.ArrayImage = pixel_ptr;
	arrayImage.height = png_get_image_height(png_ptr, info_ptr);
	arrayImage.width = png_get_image_width(png_ptr, info_ptr);
	arrayImage.nChannel = png_get_channels(png_ptr, info_ptr);

	//변환
	png_start_read_image(png_ptr);
	for (png_uint_32 py = 0; py < height; py++)
	{
		png_read_row(png_ptr, row, NULL);

		for (png_uint_32 px = 0; px < width; px++)
			for (int channel = 0; channel < nChannel; channel++)
				pixel_ptr[channel][py][px] = component(row, px, channel, bit_depth, nChannel);
	}



	/* freeing dynamically allocated memories */
	row = NULL;
	png_free(png_ptr, row);
	png_destroy_info_struct(png_ptr, &info_ptr);
	png_destroy_read_struct(&png_ptr, NULL, NULL);

	return arrayImage;
}


int ArrayImage2Ascii(sArrayImage arr)
{	
	printf("entry arrayImage2Ascii\n");

	unsigned int** ascii = (unsigned int**)malloc(sizeof(unsigned int*) * arr.height);
	for (int i = 0; i < arr.height; i++)
		ascii[i] = (unsigned int*)malloc(sizeof(unsigned int) * arr.width);

	//Color_type : gray  or  gray + alpha
	if (arr.nChannel == 1 || arr.nChannel == 2)
	{
		for (int i = 0; i < arr.height; i++)
			for (int j = 0; j < arr.width; j++)
				ascii[i][j] = arr.ArrayImage[0][i][j];
	}
	//Color_type : RGB or RGB + alpha
	else if (arr.nChannel == 3 || arr.nChannel == 4)
	{
		for (int i = 0; i < arr.height; i++)
			for (int j = 0; j < arr.width; j++)
					ascii[i][j] = (unsigned int)(arr.ArrayImage[0][i][j] + arr.ArrayImage[1][i][j] + arr.ArrayImage[2][i][j]) / 3;
	}

	char ascii_character[9] = { '.', ',', '-','~', '+', '*', '#', '&', '@' };
	
	//bit depth 8bit 가정
	for (int i = 0; i < arr.height; i++)
		for (int j = 0; j < arr.width; j++)
			if (ascii[i][j] == 255)
				ascii[i][i] = ascii_character[8];
			else
				ascii[i][j] = ascii_character[(int)((float)ascii[i][j] / 255 * 9)];

	FILE* ffp = fopen("result_ascii.txt", "w");
	if (ffp == NULL)
	{
		fprintf(stderr, "could not open result_ascii.txt\n");
		exit(1);
	}
	for (int h = 0; h < arr.height; h++)
	{
		for (int w = 0; w < arr.width; w++)
			//fprintf(ffp, "%c", ascii[h][w]);
			fprintf(ffp, "%c", ascii[h][w]);
		fprintf(ffp, "\n");
	}
	fclose(ffp);




	for (int i = 0; i < arr.height; i++)
		free(ascii[i]);
	free(ascii);

}



static unsigned int
component(png_const_bytep row, png_uint_32 x, unsigned int c, unsigned int bit_depth, unsigned int channels)
{
	/* PNG images can be up to 2^31 pixels wide, but this means they can be up to
	 * 2^37 bits wide (for a 64-bit pixel - the largest possible) and hence 2^34
	 * bytes wide.  Since the row fitted into memory, however, the following must
	 * work:
	 */
	png_uint_32 bit_offset_hi = bit_depth * ((x >> 6)* channels);
	png_uint_32 bit_offset_lo = bit_depth * ((x & 0x3f) * channels + c);

	row = (png_const_bytep)(((const png_byte(*)[8])row) + bit_offset_hi);
	row += bit_offset_lo >> 3;
	bit_offset_lo &= 0x07;

	/* PNG pixels are packed into bytes to put the first pixel in the highest
	 * bits of the byte and into two bytes for 16-bit values with the high 8 bits
	 * first, so:
	 */
	switch (bit_depth)
	{
	case 1: return (row[0] >> (7 - bit_offset_lo)) & 0x01;
	case 2: return (row[0] >> (6 - bit_offset_lo)) & 0x03;
	case 4: return (row[0] >> (4 - bit_offset_lo)) & 0x0f;
	case 8: return row[0];
	case 16: return (row[0] << 8) + row[1];
	default:
		/* This should never happen; it indicates a bug in this program or in
		 * libpng itself:
		 */
		fprintf(stderr, "pngpixel: invalid bit depth %u\n", bit_depth);
		exit(1);
	}
}

