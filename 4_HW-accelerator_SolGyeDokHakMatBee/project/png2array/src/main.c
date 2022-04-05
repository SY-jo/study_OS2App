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

	//filestream �� �̿��� png_struct �� 2�� �̻� �����, 2�������ʹ� magic number�� ����� �� �о
	//libpng error : Not a PNG file ��	�߻�
	//libpng �� �ڵ带 �м��غ��� ������ ã���� ������, ���C��� ���� �������� ����
	//png2array �� array�� �����Ҵ� �ؼ� ��ȯ�ϰ�, function call �� �� scope �ʿ��� free �� �ϵ��� ��������

	//function call png2array
	sArrayImage image = png2array(f);

	//��ȯ����� text�� Ȯ��
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

	//��ȯ����� ASCII art �� Ȯ��
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