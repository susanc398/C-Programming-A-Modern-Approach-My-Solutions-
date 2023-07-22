/* Finds the largest number in a series of number entered by the user */

#include <stdio.h>

int main(void)
{
    float number, largest;
    
    printf("Enter a number: ");
    scanf("%f", &number);
    largest = number;

    while (number > 0) {
        printf("Enter a number: ");
        scanf("%f", &number);

        if (number > largest)
            largest = number;
    }

    printf("The largest number entered was %g\n", largest);

    return 0;
}