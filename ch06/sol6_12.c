/* Approximates Euler's constant */

#include <stdio.h>

int main(void)
{
    double epsilon, e = 1, term;
    int i = 1, j, fact = 1;

    printf("Enter value for epsilon: ");
    scanf("%lf", &epsilon);

    for (;;) {
        for (j = 1; j <= i; j++) {
            fact *= j;
        }
        term = 1.0 / fact;
        if (term < epsilon) break;
        e += term;
        i++;
    }

    printf("%lg\n", e);

    return 0;
}