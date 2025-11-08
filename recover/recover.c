#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s image", argv[0]);
        return 1;
    }
    FILE *image = fopen(argv[1], "r");
    if (image == NULL)
    {
        printf("Could not open %s", argv[1]);
        fclose(image);
        return 1;
    }

    uint8_t buf[512];
    int files = 0;
    FILE *jpg = NULL;
    char filename[8];

    while (fread(buf, sizeof(buf), 1, image) == 1)
    {
        if (buf[0] == 0xff && buf[1] == 0xd8 &&
            buf[2] == 0xff)
        {
            if (jpg != NULL)
            {
                fclose(jpg);
            }

            sprintf(filename, "%03d.jpg", files);
            jpg = fopen(filename, "wb");
            if (jpg == NULL)
            {
                fclose(image);
                fprintf(stderr, "Could not create JPEG file.\n");
                return 2;
            }

            files++;
        }

        if (jpg != NULL)
        {
            fwrite(buf, sizeof(buf), 1, jpg);
        }
    }

    if (jpg != NULL)
    {
        fclose(jpg);
    }
    fclose(image);
}
