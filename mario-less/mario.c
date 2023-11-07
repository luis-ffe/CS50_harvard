#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int h;

    do
    {
        h = get_int("Set height betwen 8 and 1:  ");
    }
    while (h < 1 || h > 8); //while this condition isnt true it will keep prompting user

    for (int x = 0; x < h; x++)
        //sets x as 0 checks if it is lower than h and. if so it increments the value by one and if it still is lower than h it runs
    {
        for (int y = 0; y < h; y++)
        {
            if (x + y < h - 1) // the sum of x and y needs to be lower than h -1 and this will print the spaces
            {
                printf(" ");
            }
            else                 //else it will print the # and then a new line as the values have all reached their maximum
            {
                printf("#");
            }
        }
        printf("\n");
    }
}