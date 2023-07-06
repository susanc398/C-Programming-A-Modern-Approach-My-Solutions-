/* Calculates the remaining value of a loan after the first, second, and third payments */

#include <stdio.h>

int main(void)
{
    float loan, interest, payment, balance;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest);
    printf("Enter monthly payment: ");
    scanf("%f", &payment);

    balance = loan - payment + (loan * (interest / 12 / 100));
    printf("\nBalance remaining after first payment: $%.2f\n", balance);
    balance = balance - payment + (balance * (interest / 12 / 100));
    printf("Balance remaining after second payment: $%.2f\n", balance);
    balance = balance - payment + (balance * (interest / 12 / 100));
    printf("Balance remaining after third payment: $%.2f\n", balance);

    return 0;
}