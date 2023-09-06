/* Prints a table of compound interest */

#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void)
{
    int i, low_rate, num_years, month, num_months;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    num_months = num_years * 12;

    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (month = 1; month <= num_months; month++) {
        if (month % 12 == 0)
            printf("%3d   ", month / 12);
        for (i = 0; i < NUM_RATES; i++) {
            value[i] += (low_rate / 12.0 + i / 12.0) / 100.0 * value[i];
            if (month % 12 == 0)
                printf("%7.2f", value[i]);
        }
        if (month % 12 == 0)
            printf("\n");
    }

    return 0;
}