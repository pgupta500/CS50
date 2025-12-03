#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i<height; i++){
        for(int a = 0; a<width; a++){
            int avg = round((image[i][a].rgbtBlue+image[i][a].rgbtGreen+image[i][a].rgbtRed)/3.0);
            image[i][a].rgbtBlue = avg;
            image[i][a].rgbtGreen = avg;
            image[i][a].rgbtRed = avg;
        }
    }
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < width / 2; a++)
        {
            int opposite = width - 1 - a;

            RGBTRIPLE temp = image[i][a];
            image[i][a] = image[i][opposite];
            image[i][opposite] = temp;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < width; a++)
        {
            copy[i][a] = image[i][a];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < width; a++)
        {
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            int count = 0;

            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    int neighbor_row = i + r;
                    int neighbor_col = a + c;

                    if (neighbor_row >= 0 && neighbor_row < height && neighbor_col >= 0 && neighbor_col < width)
                    {
                        sumBlue += copy[neighbor_row][neighbor_col].rgbtBlue;
                        sumGreen += copy[neighbor_row][neighbor_col].rgbtGreen;
                        sumRed += copy[neighbor_row][neighbor_col].rgbtRed;
                        count++;
                    }
                }
            }

            image[i][a].rgbtBlue = round((float)sumBlue / count);
            image[i][a].rgbtGreen = round((float)sumGreen / count);
            image[i][a].rgbtRed = round((float)sumRed / count);
        }
    }
    return;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < width; a++)
        {
            copy[i][a] = image[i][a];
        }
    }

    int Gx_kernel[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy_kernel[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int a = 0; a < width; a++)
        {
            long gxBlue = 0, gyBlue = 0;
            long gxGreen = 0, gyGreen = 0;
            long gxRed = 0, gyRed = 0;

            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    int neighbor_row = i + r;
                    int neighbor_col = a + c;

                    int kernel_row = r + 1;
                    int kernel_col = c + 1;

                    if (neighbor_row >= 0 && neighbor_row < height && neighbor_col >= 0 && neighbor_col < width)
                    {
                        RGBTRIPLE neighbor = copy[neighbor_row][neighbor_col];

                        gxBlue += Gx_kernel[kernel_row][kernel_col] * neighbor.rgbtBlue;
                        gxGreen += Gx_kernel[kernel_row][kernel_col] * neighbor.rgbtGreen;
                        gxRed += Gx_kernel[kernel_row][kernel_col] * neighbor.rgbtRed;

                        gyBlue += Gy_kernel[kernel_row][kernel_col] * neighbor.rgbtBlue;
                        gyGreen += Gy_kernel[kernel_row][kernel_col] * neighbor.rgbtGreen;
                        gyRed += Gy_kernel[kernel_row][kernel_col] * neighbor.rgbtRed;
                    }
                }
            }

            int finalBlue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            int finalGreen = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            int finalRed = round(sqrt(gxRed * gxRed + gyRed * gyRed));

            image[i][a].rgbtBlue = (finalBlue > 255) ? 255 : finalBlue;
            image[i][a].rgbtGreen = (finalGreen > 255) ? 255 : finalGreen;
            image[i][a].rgbtRed = (finalRed > 255) ? 255 : finalRed;
        }
    }
    return;
}
