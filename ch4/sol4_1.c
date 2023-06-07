/* Prints two input digits reversed */

#include <stdio.h>

int main(void)
{
    int d1, d2;

    printf("Enter a two-digit number: ");
    scanf("%d", &d1);

    d2 = d1 / 10;
    d1 %= 10;

    printf("The reversal is: %d%d\n", d1, d2);

    return 0;
}