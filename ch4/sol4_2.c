/* Prints three input digits reversed */

#include <stdio.h>

int main(void)
{
    int d1, d2, d3;

    printf("Enter a three-digit number: ");
    scanf("%d", &d1);

    d3 = d1 / 100;
    d2 = d1 % 100 / 10;
    d1 %= 10;

    printf("The reversal is: %d%d%d\n", d1, d2, d3);

    return 0;
}