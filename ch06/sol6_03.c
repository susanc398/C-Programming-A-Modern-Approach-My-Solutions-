/* Reduces fraction to lowest terms */

#include <stdio.h>

int main(void)
{
    int num, denom, remainder, n, m;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &denom);

    n = num;
    m = denom;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    printf("In lowest terms: %d/%d\n", num / m, denom / m);

    return 0;
}