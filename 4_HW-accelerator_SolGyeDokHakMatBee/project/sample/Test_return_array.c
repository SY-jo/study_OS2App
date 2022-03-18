#include <stdio.h>

int main(void)
{

	char ascii_character[9] = { '.', ',', '-','~', '+', '*', '#', '&', '@' };


	int arr[16][16];
    int cnt = 0;
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
            arr[i][j] = cnt++;
    
    for (int i = 0; i < 16; i++)
    {
		for (int j = 0; j < 16; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    } 

    printf("\n");
    printf("\n");

	// for (int i = 0; i < 16; i++)
	// 	for (int j = 0; j < 16; j++)
    //         arr[i][j] = (int)((float)arr[i][j] / 255 * 9);


	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++)
			if (arr[i][j] == 255)
				arr[i][i] = (unsigned int)ascii_character[8];
			else
				arr[i][j] = (unsigned int)ascii_character[(int)((float)arr[i][j] / 255 * 9)];

    for (int i = 0; i < 16; i++)
    {
		for (int j = 0; j < 16; j++)
            printf("%c ", arr[i][j]);
        printf("\n");
    } 

    return 0;
}