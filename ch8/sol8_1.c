/* Modifies repdigit such that the program prints out the repeated digits */

#include <stdbool.h>
#include <stdio.h>

int main(void) 
{
    bool digit_seen[10] = {false};
    bool digit_repeat[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit])
            digit_repeat[digit] = true;
        digit_seen[digit] = true;
        n /= 10;
    }

    printf("Repeated digit(s):");
    for (digit = 0; digit < 10; digit++)
        if (digit_repeat[digit])
            printf(" %d", digit);
    printf("\n");

    return 0;
}