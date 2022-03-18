#include <stdlib.h>
#include <stdio.h>
#include "png.h"
#include "zlib.h"

#define ERROR -1


typedef struct _sImage_size
{
	png_uint_32 height;
	png_uint_32 width;
	png_byte nChannel;
}sImage_size;


// ArrayImage : png 이미지의 채널별 pixel value 를 담고있는 array. [channel][height][width]
// height, width : array size
// nChannel : 채널의 개수. original image의 color type에 따라서 달라짐
// 		1 : arr[0] - gray
// 		2 : arr[0] - gray , arr[1] - alpha
// 		3 : arr[0] - red , arr[1] - green , arr[2] - blue
// 		4 : arr[0] - red , arr[1] - green , arr[2] - blue, arr[3] - alpha
typedef struct _sArrayImage
{
	unsigned int*** ArrayImage;
	png_uint_32 height;
	png_uint_32 width;
	png_byte nChannel;
}sArrayImage;

//png2array 를 call하는 scope에서 동적할당을 하기 위해 만들었던 함수.
//폐기
sImage_size Get_image_size(FILE* hImage);

//png 파일을 보내주면, 변환된 array를 포함한 sArrayImage 를 반환
//함수 내부에서 동적할당을 함. 
//때문에 png2array 를 call한 scope에서 sArrayImage.ArrayImage를 free() 해줘야됨
sArrayImage png2array(FILE* hImage);

//출력결과를 ASCII 문자로 변환해서 텍스트 에디터로 출력결과를 확인하려고 만든 함수.
//return type을 void로 했더니 컴파일러가 function을 통째로 날려버림.
//return 값에는 의미를 두지 않았음
int ArrayImage2Ascii(sArrayImage arr);

/* Return component 'c' of pixel 'x' from the given row. */
static unsigned int
component(png_const_bytep row, png_uint_32 x, unsigned int c, unsigned int bit_depth, unsigned int channels);