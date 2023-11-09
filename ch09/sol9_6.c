/* Computes the value of x given that f(x) = 3x^5 + 2x^4 - 5x^3 - x^2 +7x - 6 */

#include <stdio.h>

int power(int x, int n);
int f(int x);

int main(void)
{
    int x, y;

    printf("Enter a value for x: ");
    scanf("%d", &x);

    y = f(x);
    printf("The output is %d\n", y);

    return 0;
}

int power(int x, int n)
{
    if (n == 0)
        return 1;
    else
        return x * power(x, n - 1);
}

int f(int x)
{
    int term1, term2, term3, term4, term5;

    term1 = 3 * power(x, 5);
    term2 = 2 * power(x, 4);
    term3 = 5 * power(x, 3);
    term4 = power(x, 2);
    term5 = 7 * power(x, 1);
    
    return term1 + term2 - term3 - term4 + term5 - 6;
}