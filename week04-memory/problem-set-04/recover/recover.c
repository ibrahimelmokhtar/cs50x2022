#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;
typedef char* string;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[]) {
    // Display appropriate error message:
    if (argc != 2) {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open specific image in read mode:
    FILE* file = fopen(argv[1], "r");
    if (ferror(file)) {
        printf("Can NOT open this file\n");
        return 1;
    }

    BYTE HEADER_BYTES[] = {
        0xff,
        0xd8,
        0xff,
    };

    int image_counter=0;
    BYTE* block = malloc(BLOCK_SIZE*sizeof(BYTE));

    while (fread(block, sizeof(BYTE), BLOCK_SIZE, file)) {
        int bytes_counter=0;
        for (int i=0; i<3; i++) {
            if (block[i] != HEADER_BYTES[i]) {
                break;
            }

            bytes_counter++;
        }

        // It's a valid JPEG file:
        if (bytes_counter == 3) {
            // Construct output file name:
            string name_buffer = malloc(7*sizeof(char));
            sprintf(name_buffer, "%03i.jpg", image_counter);

            // Create and open the output file in write mode:
            FILE* output = fopen(name_buffer, "w");

            // Write the data into output image file:
            fwrite(block, sizeof(BYTE), BLOCK_SIZE, output);

            // Close output file:
            fclose(output);

            // Free allocated memory:
            free(name_buffer);

            // Increase images counter:
            image_counter++;
        }
    }

    // Close input file:
    fclose(file);

    // Free allocated memory:
    free(block);

    return 0;
}
