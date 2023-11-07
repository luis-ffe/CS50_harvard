#include <stdio.h>
#include <cs50.h>
//packages with new tools to work with in my code

int main(void)
{
    //this will ask for user imput telling the string shown insede it
    string name = get_string("Tell me your name, please?");
    printf("Hello, %s\n", name); //this will print the hello, name that was input as a string only
}

//only seen the style50 command latter thus making the coments now after sending the first version alreadyu