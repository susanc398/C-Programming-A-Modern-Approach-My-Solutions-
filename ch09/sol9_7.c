/* Calculates x raised to the power of n (faster version) */

#include <stdio.h>

int power(int x, int n);
int compute_power(int x, int n);

int main(void)
{
    int x, n, result;

    printf("Enter a value for x: ");
    scanf("%d", &x);
    printf("Enter a value for n: ");
    scanf("%d", &n);

    result = compute_power(x, n);

    printf("The result of %d raised to the power of %d is %d\n", x, n, result);

    return 0;
}

int power(int x, int n)
{
    if (n == 0)
        return 1;
    else 
        return x * power(x, n - 1);
}

int compute_power(int x, int n)
{
    if (n == 0)
        return 1;

    return n % 2 == 0 ? power(power(x, n / 2), 2) : x * compute_power(x, n - 1);
}