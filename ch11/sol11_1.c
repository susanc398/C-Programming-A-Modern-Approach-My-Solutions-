/* Modifies programming project 7 from chapter 2 to include another function */

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main(void)
{
    int amount, bills20, bills10, bills5, bills1;

    printf("Enter a dollar amount: ");
    scanf("%d", &amount);

    pay_amount(amount, &bills20, &bills10, &bills5, &bills1);

    printf("\n");
    printf("$20 bills: %d\n", bills20);
    printf("$10 bills: %d\n", bills10);
    printf("$5 bills: %d\n", bills5);
    printf("$1 bills: %d\n", bills1);

    return 0;
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{
    *twenties = dollars / 20;
    dollars %= 20;
    *tens = dollars / 10;
    dollars %= 10;
    *fives = dollars / 5;
    dollars %= 5;
    *ones = dollars;
}