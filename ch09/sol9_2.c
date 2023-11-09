/* Calculates tax due based on income using function call */

#include <stdio.h>

float find_tax(float income)
{
    float tax;

    if (income <= 750)
        tax = 0.01f * income;
    else if (income > 750 && income <= 2250)
        tax = 7.50f + 0.02f * (income - 750);
    else if (income > 2250 && income <= 3750)
        tax = 37.50f + 0.03f * (income - 3750);
    else if (income > 3750 && income <= 5250)
        tax = 82.50f + 0.04f * (income - 3750);
    else if (income > 5250 && income <= 7000)
        tax = 142.50f + 0.05f * (income - 5250);
    else if (income > 7000)
        tax = 230.00f + 0.06f * (income - 7000);

    return tax;
}

int main(void)
{
    float taxableIncome, taxDue;

    printf("Enter amount of taxable income: ");
    scanf("%f", &taxableIncome);

    taxDue = find_tax(taxableIncome);

    printf("Tax: $%.2f\n", taxDue);

    return 0;
}