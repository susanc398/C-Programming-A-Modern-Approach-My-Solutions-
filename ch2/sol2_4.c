/* Adds 5% tax to given amount */

#include <stdio.h>

int main(void)
{
    float amount, newAmount;

    printf("Enter an amount: ");
    scanf("%f", &amount);

    printf("With tax added: $%.2f\n", amount + 0.05f * amount);

    return 0;
}