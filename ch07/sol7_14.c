/* Uses Newton's method to compute the square root of a positive floating-point number */

#include <math.h>
#include <stdio.h>

int main(void)
{
    double x, y = 0, x_over_y, new_y = 1;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    while (fabs(y - new_y) >= (.00001 * y)) {
        y = new_y;
        x_over_y = x / y;
        new_y = (y + x_over_y) / 2;
    }

    printf("Square root: %.5lf\n", y);

    return 0;
}