/* Prints all even squares between 1 and user-inputed value */

#include <stdio.h>

int main(void)
{
    int number, i;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("All even squares between 1 and %d are:\n", number);
    for (i = 2; i * i < number; i+=2) {
        printf("%d\n", i * i);
    }

    return 0;
}