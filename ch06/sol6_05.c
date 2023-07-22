/* Reverses digits of a number */

#include <stdio.h>

int main(void)
{
    long num;

    printf("Enter a number: ");
    scanf("%ld", &num);

    printf("The reversal is: ");
    do {
        printf("%ld", num % 10);
        num /= 10;
    } while ((num % 10) > 0);
    printf("\n");

    return 0;
}