/* Prints out telephone number in the format xxx.xxx.xxxx */

#include <stdio.h>

int main(void)
{
    int d1, d2, d3;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d", &d1, &d2, &d3);
    printf("You entered %d.%d.%d\n", d1, d2, d3);

    return 0;
}