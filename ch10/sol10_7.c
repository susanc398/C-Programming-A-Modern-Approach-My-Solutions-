#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

/* external variables */
const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                             {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};
int digits[4][MAX_DIGITS * 4];
const int segment_grid[7][2] = {{0, 1},
                                {1, 2},
                                {2, 2},
                                {2, 1},
                                {2, 0},
                                {1, 0},
                                {1, 1}};

/* prototypes */
void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
    int ch, pos = 0;

    clear_digits_array();

    printf("Enter a number: ");
    while ((ch = getchar()) != '\n') {
        if (isdigit(ch)) {
            process_digit(ch - '0', pos);
            pos += 4;
        }
    }

    print_digits_array();

    return 0;
}

/*
 * clear_digits_array: initializes the external array digits with all zeros
 */
void clear_digits_array(void)
{
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < MAX_DIGITS * 4; j++)
            digits[i][j] = ' ';
    }
}

void process_digit(int digit, int position)
{
    int i, row, col;

    for (i = 0; i < 7; i++) {
        if (segments[digit][i] == 1) {
            row = segment_grid[i][0];
            col = segment_grid[i][1] + position;

            if (col % 2 == 0) 
                digits[row][col] = '|';
            else if (col % 2 == 1)
                digits[row][col] = '_';
        }
    }
}

void print_digits_array(void)
{
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < MAX_DIGITS * 4; j++) {
            putchar(digits[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}