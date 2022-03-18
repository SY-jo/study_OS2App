#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char arr[2][3][4] = {1, 2, 3, 4, 5, 6, 7, 8};
    char temp = 0;
    for(int k = 0; k < 2; k++)
        for(int j = 0; j < 3; j++)
            for(int i = 0; i < 4; i++)
                arr[k][j][i] = temp++;
                
    
    int channel = 2;
    int height = 3;
    int width = 4;
    
    //3차원 배열 동적할당
    char*** arr_ptr = (char***)malloc(sizeof(char**) * channel);
    for(int c = 0; c < channel; c++)
    {
        arr_ptr[c] = (char**)malloc(sizeof(char*) * height);
        for(int h = 0; h < height; h++)
            arr_ptr[c][h] = (char*)malloc(sizeof(char) * width);
    }


    for(int c = 0; c < channel; c++)
        for(int h = 0; h < height; h++)
            for(int w = 0; w < width; w++)
                arr_ptr[c][h][w] = arr[c][h][w];

    printf("arr[0][][] \n");
 

    FILE* fp = fopen("result.txt", "w");
    for(int k = 0; k < channel; k++)
    {
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
                fprintf(fp, "%d  ", arr_ptr[k][i][j]);
            fprintf(fp, "\n");
        }
        fprintf(fp, "\n\n");
    }


    //3차원 배열 반환
    for(int c = 0; c < channel; c++)
    {
        for(int h = 0; h < height; h++)
            free(arr_ptr[c][h]);
        free(arr_ptr[c]);
    }
    free(arr_ptr);

    return 0;
}