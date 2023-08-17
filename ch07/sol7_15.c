/* Computes the factorial of a positive integer */

#include <stdio.h>

int main(void)
{
    int i, integer, factorial = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &integer);

    if (integer > 0) {
        for (i = 1; i <= integer; i++) {
            factorial *= i;
        }
    }

    printf("Factorial of %d: %d\n", integer, factorial);

    return 0;
}