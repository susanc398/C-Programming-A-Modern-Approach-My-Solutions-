/* Approximates Euler's constant */

#include <stdio.h>

int main(void)
{
    int n, i = 0, j, fact = 1;
    double e = 1;
    printf("Enter value for n: ");
    scanf("%d", &n);

    while (i < n) {
        if (i == 0) {
            i++;
            continue;
         } else {
            for (j = 1; j <= i; j++) 
                fact *= j;
            e += 1.0 / fact;
            i++;
        }
    }

    printf("%lg\n", e);

    return 0;
}