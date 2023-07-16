/* Converts numerical grade into letter grade */

#include <stdio.h>

int main(void)
{
    int grade, d;

    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    if (grade < 0 || grade > 100)
        printf("--ERROR--");
    else {
        printf("Letter grade: ");

        d = grade / 10;
        switch (d) {
            case 9:
                printf("A");
                break;
            case 8:
                printf("B");
                break;
            case 7:
                printf("C");
                break;
            case 6: 
                printf("D");
                break;
            case 5: case 4: case 3: case 2: case 1: case 0: 
                printf("F");
                break;
        }
    }
    printf("\n");

    return 0;
}