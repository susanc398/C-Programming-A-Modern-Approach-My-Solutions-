/* Creates an nxn magic square, where n is odd */

#include <stdio.h>

int main(void)
{
    int n, row, col, count = 1, prev_row, prev_col;

    printf("\nThis program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    int magic_square[n][n]; 

    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++)
            magic_square[row][col] = 0;
    }

    row = 0;
    col = 2;
    magic_square[row][col] = count++;
    while (count <= n * n) {
        prev_row = row;
        prev_col = col;
        row = row - 1 < 0 ? row - 1 + n: row - 1;
        col = (col + 1) % n;
        if (magic_square[row][col] > 0) {
            row = prev_row + 1;
            col = prev_col;
        }
        magic_square[row][col] = count++;
    }

    for (row = 0; row < n; row++) {
        for (col = 0; col < n; col++)
            printf("%3d", magic_square[row][col]);
        printf("\n");
    }

    return 0;
}