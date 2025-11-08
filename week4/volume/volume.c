// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;
typedef int16_t sample;
typedef uint8_t byte;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    byte buffer[44];
    fread(buffer, sizeof(buffer), 1, input);
    fwrite(buffer, sizeof(buffer), 1, output);

    sample buf;

    // Loop from cp.c in the lecture
    while (fread(&buf, sizeof(buf), 1, input) != 0)
    {
        buf = buf * factor;
        fwrite(&buf, sizeof(buf), 1, output);
    }

    fclose(input);
    fclose(output);
}
