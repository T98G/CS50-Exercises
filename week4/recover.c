#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Recover takes exactly 1 argument, but %i were given.\n", argc - 1);
        return 1;
    }

    BYTE buffer[512];
    int file_num = 0;
    char file_name[9];
    bool found_jpeg = false;

    FILE *file = fopen(argv[1], "r");
    FILE *img;

    while (fread(buffer, 1, 512, file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (file_num == 0)
            {
                sprintf(file_name, "%03i.jpg", file_num);
                img = fopen(file_name, "w");
                fwrite(buffer, 512, 1, img);
                found_jpeg = true;
                file_num ++;
            }
            else
            {
                fclose(img);
                sprintf(file_name, "%03i.jpg", file_num);
                img = fopen(file_name, "w");
                fwrite(buffer, 512, 1, img);
                file_num ++;
            }
        }
        else
        {
            if (found_jpeg)
            {
                fwrite(buffer, 512, 1, img);
            }
        }
    }

    fclose(img);
    fclose(file);

    return 0;
}


