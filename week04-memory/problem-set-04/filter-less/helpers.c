#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            // Calculate new grayscale value
            int gray = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3;

            // Update pixel values
            image[i][j].rgbtBlue = gray;
            image[i][j].rgbtGreen = gray;
            image[i][j].rgbtRed = gray;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            // Calculate new sepia values
            int sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
            int sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            int sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;

            // Limit sepia values to 255
            if (sepiaBlue > 255) {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255) {
                sepiaGreen = 255;
            }
            if (sepiaRed > 255) {
                sepiaRed = 255;
            }

            // Update pixel values
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
    for (int i=0; i<height; i++) {
        for (int j=0; j<width/2; j++) {
            // Swap TWO pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
    int window_size = 9;
    RGBTRIPLE result[height][width];

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            // Reset average values:
            int avg_blue=0, avg_green=0, avg_red=0;

            // Calculate average over specific window
            for (int row=i-(window_size/2); row<i-(window_size/2)+window_size; row++) {
                // Validate window index
                if (row<0 || row > height-1) {
                    continue;
                }

                for (int col=j-(window_size/2); col<j-(window_size/2)+window_size; col++) {
                    // Validate window index
                    if (col<0 || col>width-1) {
                        continue;
                    }

                    //  Calculate average values
                    avg_blue += image[row][col].rgbtBlue;
                    avg_green += image[row][col].rgbtGreen;
                    avg_red += image[row][col].rgbtRed;
                }
            }
            result[i][j].rgbtBlue = avg_blue/(window_size*window_size);
            result[i][j].rgbtGreen = avg_green/(window_size*window_size);
            result[i][j].rgbtRed = avg_red/(window_size*window_size);
        }
    }

    // Copy result into original image
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            image[i][j].rgbtBlue = result[i][j].rgbtBlue;
            image[i][j].rgbtGreen = result[i][j].rgbtGreen;
            image[i][j].rgbtRed = result[i][j].rgbtRed;
        }
    }

    return;
}
