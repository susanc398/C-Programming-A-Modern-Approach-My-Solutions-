/* Calculates the remaining value of a loan after the first, second, and third payments */

#include <stdio.h>

int main(void)
{
    float loan, interest, payment, balance;
    int no_payments, i = 1;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest);
    printf("Enter monthly payment: ");
    scanf("%f", &payment);
    printf("Enter number of payments: ");
    scanf("%d", &no_payments);

    balance = loan;
    printf("\n");
    while (i <= no_payments) {
        balance = balance - payment + (balance * (interest / 12 / 100));
        printf("Balance remaining after payment number %d: $%.2f\n", i++, balance);
    }

    return 0;
}