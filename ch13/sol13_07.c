/* Prints the english word for a two-digit number */

#include <stdio.h>

int main(void)
{
    int d1, d2;
    char *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty",
                    "seventy", "eighty", "ninety"};
    char *ones[] = {"-one", "-two", "-three", "-four", "-five", "-six", 
                    "-seven", "-eight", "-nine"};
    char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                     "sixteen", "seventeen", "eighteen", "nineteen"};

    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &d1, &d2);

    printf("You entered the number ");
    if (d1 == 1) {
        printf("%s", teens[d2]);
    } else {
        printf("%s", tens[d1-2]);
        if (d2 > 0) 
            printf("%s", ones[d2-1]);
    }
    printf(".\n");

    return 0;
}