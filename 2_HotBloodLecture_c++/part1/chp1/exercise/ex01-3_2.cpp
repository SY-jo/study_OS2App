#include <iostream>

int BoxVolume(int length);
int BoxVolume(int length, int width);
int BoxVolume(int length, int width, int height);

int main(void)
{
    std::cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << std::endl;
    std::cout << "[5, 5, D] : " << BoxVolume(5, 5) << std::endl;
    std::cout << "[7, D, D] : " << BoxVolume(7) << std::endl;

    return 0;
}

int BoxVolume(int length)
{
    int width = 1, height = 1;
    return length * width * height;
}

int BoxVolume(int length, int width)
{
    int height = 1;
    return length * width * height;
}

int BoxVolume(int length, int width, int height)
{
    return length * width * height;
}