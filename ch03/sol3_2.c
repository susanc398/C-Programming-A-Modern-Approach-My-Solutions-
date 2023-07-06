/* Formats product info entered by user */

#include <stdio.h>

int main(void)
{
    int item_no;
    float unit_price;
    int month, day, year;

    printf("Enter item number: ");
    scanf("%d", &item_no);
    printf("Enter unit price: ");
    scanf("%f", &unit_price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("\nItem\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%-d\t\t$%7.2f\t%-2.2d/%-2.2d/%-d\n",
        item_no, unit_price, month, day, year);

    return 0;
}