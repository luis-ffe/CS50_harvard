#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height, row, column, space;
    do
    {
        height = get_int("What will be the height:  ");
    }
    while (height < 1 || height > 8);

    for (row = 0; row < height; row++)
//conditions for the column ash or space to be printed   made a tabele and compared values to find a pattern
    {
        for (column = 0; column < height + row + 3; column++)
        {
            if (column == height || column == height + 1 || column + row < height - 1)
//only when the column or column equals height + 1 or the other are true are spaces printed otherwise its space
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
//changes lines

    }
}
