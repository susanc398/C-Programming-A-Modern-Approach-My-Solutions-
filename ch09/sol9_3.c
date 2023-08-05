/* Generates a random walk across a 10x10 array such that the elements visited are labeled 'A' through 'Z' (function version) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main(void)
{
    char board[10][10];
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            board[i][j] = '.';
        }
    }

    generate_random_walk(board);

    print_array(board);

    return 0;
}

void generate_random_walk(char walk[10][10])
{
    int letter = 'A', move, i = 0, j = 0;

    srand((unsigned) time(NULL));

    walk[i][j] = letter++;
    do {
        move = rand() % 4;

        switch (move) {
            case 3: /* move down */
                if (j + 1 < 10 && walk[i][j+1] == '.')
                    walk[i][++j] = letter++;
                break;
            case 2: /* move up */
                if (j - 1 >= 0 && walk[i][j-1] == '.')
                    walk[i][--j] = letter++;
                break;
            case 1: /* move right */
                if (i + 1 < 10 && walk[i+1][j] == '.')
                    walk[++i][j] = letter++;
                break;
            case 0: /* move left */
                if (i - 1 >= 0 && walk[i-1][j] == '.')
                    walk[--i][j] = letter++;
                break;
        }
    } while (i < 10 && j < 10 && letter <= 'Z');
}

void print_array(char walk[10][10])
{
    int i, j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j< 10; j++) {
            printf("%3c", walk[i][j]);
        }
        printf("\n");
    }
}