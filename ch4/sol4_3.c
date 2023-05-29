/* Prints three input digits reversed w/o using arithmetic */

#include <stdio.h>

int main(void)
{
    int d1, d2, d3;

    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &d3, &d2, &d1);

    printf("The reversal is: %d%d%d\n", d1, d2, d3);

    return 0;
}