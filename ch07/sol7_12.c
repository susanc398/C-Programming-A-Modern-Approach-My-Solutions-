/* Evaluates an expression */

#include <stdio.h>

int main(void)
{
    float total, value;
    int ch;

    printf("Enter an expression: ");
    scanf("%f", &total);
    while ((ch = getchar()) != '\n') {
        switch (ch) {
            case '+': 
                scanf("%f", &value);
                total += value;
                break;
            case '-': 
                scanf("%f", &value);
                total -= value;
                break;
            case '*': 
                scanf("%f", &value);
                total *= value;
                break;
            case '/':
                scanf("%f", &value);
                total /= value;
                break;
        }
    }

    printf("Value of expression: %g\n", total);

    return 0;
}