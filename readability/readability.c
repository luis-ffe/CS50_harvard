#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    float nwords = 1;
    float nletters = 0;
    float sentences = 0;

    string book = get_string("Imput paragraph here:  ");

    for (int i = 0, l = strlen(book); i < l; i++)
        //vai correr todas as letras e espaços do texto inserido.
    {
        int n = book[i];

        //if((book[i] > 64 && book[i] <91) || (book[i] > 96 && book[i] <123))   substituido pela variavel n correspondente ao numero do character em ASCii

        if ((n > 64 && n < 91) || (n > 96 && n < 123))  //conta apenas letras
        {
            nletters++;
        }
        else if (n == 32)
            //conta todos os espaços mais 1 (var = 1 ) porque a ultima palavra nao tem espaço na frente. Redundancia relativa a virgulas e pontuação.
        {
            nwords++;
        }
        if (n == '.' || n == '!' || n == '?')
            //todas as maiusculas que começam uma frase sao contadas.
        {
            sentences++;
        }
    }

    float avgS = (sentences / nwords) * 100;
    float avgL = (nletters / nwords) * 100;
    float score = (0.0588 * avgL) - (0.296 * avgS) - 15.8;

    int grade = round(score);

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    //printf("words %f  letras %f  frases %f  score %f  S %f L %f\n", nwords, nletters, sentences, score, avgS, avgL);

}