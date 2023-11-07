#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float a = image[i][j].rgbtRed;
            float b = image[i][j].rgbtBlue;
            float c = image[i][j].rgbtGreen;

            int mean = round((a + b + c) / 3);

            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = mean;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;

            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);

            if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }

            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);

            if (sepiaGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }

            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            if (sepiaBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width/2); j++)
        {
            //saves a temporary data about the pixels that woil be overwritten

            int temPred = image[i][j].rgbtRed;
            int temPgreen = image[i][j].rgbtGreen;
            int temPblue = image[i][j].rgbtBlue;


            //iterates all over the pixels copying the value of the relative last pixels of the row to the start
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            //AS both pixels have the same value now we use the temporary value of the first pixels to atribute them to the relative last
            image[i][width - j - 1].rgbtRed = temPred;
            image[i][width - j - 1].rgbtGreen = temPgreen;
            image[i][width - j - 1].rgbtBlue = temPblue;
            //we could have used a simpler way usig RGBTRIPLE struct and  only image[][] without specifying the rgbtype inside the struct
        }

    }
    return;
}




// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //creating new image so the altered values do not change the next iteration values
    RGBTRIPLE temp[height][width];
    // declarar nova variavel struct acima

    //run through all the array values in the original image and copy
    //each and every one of them to the new temporary file. struct type RGBTRIPLE

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];

        }
    }


    // image copy created
    // 3 x 3 fazer media

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalr, totalb, totalg;
            totalb = totalg = totalr = 0;
            float counter = 0.00;

            //get neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentx = i + x;
                    int currenty = j + y;

                    if (currentx < 0 || currentx > (height-1) || currenty < 0 || currenty > (width-1))
                    {
                        continue;
                    }

                    //get image value

                    totalr += image[currentx][currenty].rgbtRed;
                    totalg += image[currentx][currenty].rgbtGreen;
                    totalb += image[currentx][currenty].rgbtBlue;

                    counter++;

                    temp[i][j].rgbtRed = round(totalr / counter);
                    temp[i][j].rgbtGreen = round(totalg / counter);
                    temp[i][j].rgbtBlue = round(totalb / counter);


                }
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;

        }
    }


    return;
}
