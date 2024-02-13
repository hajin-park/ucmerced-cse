#include <stdio.h>
#include <stdlib.h>


int main()
{
    int repeatCount = 0;
    int typoNum = 0;

    printf("Enter the repetition count for the punishment phrase: ");
    while (repeatCount <= 0)
    {
        scanf(" %d", &repeatCount);
        if (repeatCount <= 0)
        {
            printf("You entered an invalid value for the repetition count! Please re-enter: ");
        }
    }

    printf("Enter the line where you want to insert the typo: ");
    while (typoNum <= 0 || typoNum > repeatCount)
    {
        scanf(" %d", &typoNum);
        if (typoNum <= 0 || typoNum > repeatCount)
        {
            printf("You entered an invalid value for the typo placement! Please re-enter: ");
        }
    }

    for (int i = 0; i < repeatCount; i++)
    {
        if (i == typoNum - 1)
        {
            printf("Cading wiht is C avesone!\n");
        }
        else {
            printf("Coding with C is awesome!\n");
        }
    }
    return 0;
}