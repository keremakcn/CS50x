#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");

    if (raw_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    uint8_t buffer[512];
    int found_jpg = 1;
    int counter = 0;
    char filename[8];
    FILE *img = NULL;

    while (fread(buffer, 1, 512, raw_file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            found_jpg = 0;
        }

        if (found_jpg == 0)
        {
            if (counter != 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", counter);
            counter++;

            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);

            found_jpg = 1;
        }
        else if (counter != 0)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    // Make sure the last image is closed
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(raw_file);

    return 0;
}
