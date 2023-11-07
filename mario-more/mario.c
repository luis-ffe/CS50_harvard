#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int h, x, d, y;

    do
    {
        h = get_int("Set height betwen 8 and 1:  ");
    }
    while (h < 1 || h > 8);

    for (x = 0; x <= h; x++)
    {
        for(d = h - x; d > 0 ; d--)
        {
            printf(" ");
        }
        for (y = 0; y < x; y++)
        {
            printf("#");
        }
//ate aqui fazenos a piramide norlmal encostada á direita com os espaços na esquerda
//retirei daqui o mudar de linha e meti mai abaixo e introduzi  uma funçao if para modificar a piramide da direita e impedir um loop

        printf("  ");

        int a = x;

        if (a <= h)
        {
             for (int b = 0; b < a; b++)
             {
                printf("#");
             }

        }
        printf("\n");
    }
}
