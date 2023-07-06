/* Finds the largest in a series of numbers inputted by the user */

#include <stdio.h>

int main(void)
{
    float n, largest = 0;

    do {
        printf("Enter a number: ");
        scanf("%f", &n);

        if (n > largest)
            largest = n;
    } while(n > 0);

    printf("\nThe largest number entered was %g\n", largest);

    return 0;
}