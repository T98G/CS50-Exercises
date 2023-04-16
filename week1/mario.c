#include<cs50.h>
#include<stdio.h>

int get_height(void);
void make_pyramid(int height);

int main(void)
{
    int height = get_height();

    make_pyramid(height);
}

//only returns a valid hight

int get_height(void)

{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    return height;
}


void make_pyramid(int height)
{

    for (int row = 1; row <= height; row++)
    {
        for (int spaces = 0; spaces < height - row; spaces++) //prints the spaces before the blocks in the left
        {
            printf(" ");
        }

        for (int i = 0; i < row; i++) // prints the left hashes
        {
            printf("#");
        }

        printf("  "); // Gap

        for (int j = 0; j < row; j++) // prints the right hashes
        {
            printf("#");
        }

        printf("\n");

    }
}

