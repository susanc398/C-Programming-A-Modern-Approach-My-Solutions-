/* Computes 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 for given x */

#include <stdio.h>

int main(void)
{
    int x;

    printf("Enter a value for x: ");
    scanf("%d", &x);

    printf("%d\n", 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6);

    return 0;
}