#include <stdio.h>
#include <cs50.h>



int main()
{
    // get credit card number

    long cardNumber = get_long("Plese input your card number here:   ");

    //Count the legth of the number by dividingf by 10 we remove a number at a time increasing the length

    int length = 0;
    long cc = cardNumber;

    while (cc > 0)
        // dividinto 1000 por 10 aumenta length 1 e numero passa para 100 - depois length 2 numero passa para 10  repete numero passa para 1 e length para 3
    {
        cc = cc / 10;
        length++;
    }

    if (length != 13 && length != 15 && length != 16)
    {
        printf("INVALID\n");
        return 0;
    }


    // strat of checksum

    int sum1 = 0;
    int sum2 = 0;
    long x = cardNumber;
    int total = 0;
    int mod1;
    int mod2;
    int d1;
    int d2;

    do
    {
        // Remove last digit and add to sum1
        mod1 = x % 10; // ficou o  o 3 de 1234567890123 ou o restante ?
        x = x / 10;  // remove o 3 do numero
        sum1 = sum1 + mod1;

        // Remove second last digit
        mod2 = x % 10; // atribuir ultimo digito atual a mod 2
        x = x / 10;  //retirar esse digito do processo


        // Double second last digit and add digits to sum2
        mod2 = mod2 * 2;  // multiplica todos os segundos que foram guardados numa variavel e multiplica-os por 2
        d1 = mod2 % 10;
        d2 = mod2 / 10;
        sum2 = sum2 + d1 + d2;
    }
    while (x > 0);
    total = sum1 + sum2;

// Next check Luhn Algorithm
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    // Get starting digits
    long start = cardNumber;
    do
    {
        start = start / 10;
    }
    while (start > 100);

    // Next check starting digits for card type
    if ((start / 10 == 5) && (0 < start % 10 && start % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((start / 10 == 3) && (start % 10 == 4 || start % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (start / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}