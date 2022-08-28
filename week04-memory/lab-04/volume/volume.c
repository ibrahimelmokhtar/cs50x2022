// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Useful global variables:
const int SAMPLE_SIZE = sizeof(int16_t);
const int BYTE_SIZE = sizeof(uint8_t);

// Number of bytes in .wav header:
const int HEADER_SIZE = 44;

int main(int argc, char *argv[]) {
    // Check command-line arguments:
    if (argc != 4) {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor:
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    char* header = malloc(HEADER_SIZE*BYTE_SIZE);
    fread(header, BYTE_SIZE, HEADER_SIZE, input);
    fwrite(header, BYTE_SIZE, HEADER_SIZE, output);
    free(header);

    // TODO: Read samples from input file and write updated data to output file
    while (!feof(input)) {
        int16_t* sample = malloc(SAMPLE_SIZE);
        fread(sample, SAMPLE_SIZE, 1, input);
        for (int i=0; i<SAMPLE_SIZE; i++) {
            sample[i] = (int16_t) (sample[i] * factor);
        }
        fwrite(sample, SAMPLE_SIZE, 1, output);
        free(sample);
    }

    // Close files:
    fclose(input);
    fclose(output);
}


// printf("%li\n", ftell(output_ptr));
