#include <stdio.h>
#include <stdlib.h>
#include "png2array.h"


int main(int argc, const char** argv)
{
	char* fileName[30];
	printf("png file name : ");
	scanf("%s", &fileName);
	

	//handle for .png image file
	FILE* f = fopen(fileName, "rb");
	if (f == NULL)
	{
		fprintf(stderr, "png2array: %s: could not open file\n", argv[1]);
		exit(1);
	}

	//filestream 을 이용해 png_struct 을 2번 이상 만들면, 2번쨰부터는 magic number를 제대로 못 읽어서
	//libpng error : Not a PNG file 가	발생
	//libpng 의 코드를 분석해보며 원인을 찾으려 했으나, 고급C언어 문법 부족으로 실패
	//png2array 가 array를 동적할당 해서 반환하고, function call 을 한 scope 쪽에서 free 를 하도록 수정했음

	//function call png2array
	sArrayImage image = png2array(f);

	//변환결과를 text로 확인
	FILE* fp = fopen("result.txt", "w");
	for (int c = 0; c < image.nChannel; c++)
	{
		fprintf(fp, "channel : %d \n", c);
		for (int h = 0; h < image.height; h++)
		{
			for (int w = 0; w < image.width; w++)
				fprintf(fp, "%d ", image.ArrayImage[c][h][w]);
			fprintf(fp, "\n");
		}
		fprintf(fp, "\n\n\n");
	}
	fclose(fp);

	//변환결과를 ASCII art 로 확인
	ArrayImage2Ascii(image);


	//pixel_ptr free
	for (int c = 0; c < image.nChannel; c++)
	{
		for (int h = 0; h < image.height; h++)
			free(image.ArrayImage[c][h]);
		free(image.ArrayImage[c]);
	}
	free(image.ArrayImage);

	fclose(f);


	return 0;
}