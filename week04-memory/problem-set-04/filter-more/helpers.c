#include "helpers.h"
#include <math.h>
#include <stdio.h>

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]) {
    int GX[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };
    int GY[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

    RGBTRIPLE result[height][width];

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            // Reset sobel values:
            long gx_blue=0, gy_blue=0, gs_blue=0;
            long gx_green=0, gy_green=0, gs_green=0;
            long gx_red=0, gy_red=0, gs_red=0;

            // Calculate average over specific window
            for (int row=i-1, window_row=0; row<=i+1 && window_row<3; row++, window_row++) {
                // Validate window index
                if (row<0 || row > height-1) {
                    continue;
                }

                for (int col=j-1, window_col=0; col<=j+1 && window_col<3; col++, window_col++) {
                    // Validate window index
                    if (col<0 || col>width-1) {
                        continue;
                    }

                    // Calculate gx, gy components
                    gx_blue += image[row][col].rgbtBlue * GX[window_row][window_col];
                    gy_blue += image[row][col].rgbtBlue * GY[window_row][window_col];

                    gy_green += image[row][col].rgbtGreen * GY[window_row][window_col];
                    gx_green += image[row][col].rgbtGreen * GX[window_row][window_col];

                    gx_red += image[row][col].rgbtRed * GX[window_row][window_col];
                    gy_red += image[row][col].rgbtRed * GY[window_row][window_col];
                }
            }

            //  Calculate sobel values
            gs_blue = sqrt(pow(gx_blue, 2) + pow(gy_blue, 2));
            gs_green = sqrt(pow(gx_green, 2) + pow(gy_green, 2));
            gs_red = sqrt(pow(gx_red, 2) + pow(gy_red, 2));

            // Limit sobel values to 255
            if (gs_blue > 255) {
                gs_blue = 255;
            }

            if (gs_green > 255) {
                gs_green = 255;
            }

            if (gs_red > 255) {
                gs_red = 255;
            }

            result[i][j].rgbtBlue = gs_blue;
            result[i][j].rgbtGreen = gs_green;
            result[i][j].rgbtRed = gs_red;
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
