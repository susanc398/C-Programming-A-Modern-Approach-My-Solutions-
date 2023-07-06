/* Displays integer in octal */

#include <stdio.h>

int main(void)
{
    int n, r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &n);

    r1 = n % 8;
    n /= 8;
    r2 = n % 8;
    n /= 8;
    r3 = n % 8;
    n /= 8;
    r4 = n % 8;
    n /= 8;
    r5 = n % 8;

    printf("In octal, your number is: %d%d%d%d%d\n", r5, r4, r3, r2, r1);

    return 0;
}