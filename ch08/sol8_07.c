/* Calculates the row and column sum of an 5x5 array */

#include <stdio.h>

int main(void)
{
    int a[5][5], i, j, row_sums[5] = {}, col_sums[5] = {};

    for (i = 0; i < 5; i++) {
        printf("Enter row %d: ", i + 1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &a[i][j]);
            row_sums[i] += a[i][j];
            col_sums[j] += a[i][j];
        }
    }

    printf("\nRow totals: ");
    for (i = 0; i < 5; i++) 
        printf(" %d", row_sums[i]);
    printf("\n");

    printf("Column totals: ");
    for (j = 0; j < 5; j++)
        printf(" %d", col_sums[j]);
    printf("\n");

    return 0;
}