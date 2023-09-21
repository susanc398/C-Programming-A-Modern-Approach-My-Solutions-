/* Reduces fraction to lowest terms (pointer version) */

#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int remainder, m, n;

    n = numerator;
    m = denominator;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    *reduced_numerator = numerator / m;
    *reduced_denominator = denominator / m;
    return;
}

int main(void)
{
    int num, denom, reduced_num, reduced_denom;

    printf("Enter a fraction: ");
    scanf("%d/%d", &num, &denom);

    reduce(num, denom, &reduced_num, &reduced_denom);

    printf("In lowest terms: %d/%d\n", reduced_num, reduced_denom);

    return 0;
}