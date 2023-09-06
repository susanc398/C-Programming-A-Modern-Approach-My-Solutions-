/* Generates a random walk across a 10x10 array such that the elements visited are labeled 'A' through 'Z' */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10

int main(void)
{
    int alpha = 65, i, j, move;
    char board[BOARD_WIDTH][BOARD_HEIGHT];

    for (i = 0; i < BOARD_WIDTH; i++)
        for (j = 0; j < BOARD_HEIGHT; j++)
            board[i][j] = 46;

    srand((unsigned) time(NULL));

    board[0][0] = alpha++;

    i = 0;
    j = 0;

    do {
        move = rand() % 4;
        
        switch (move) {
            case 3: /* move down */
                if (j + 1 < 10 && board[i][j+1] == '.')
                    board[i][++j] = alpha++;
                break;
            case 2: /* move up */
                if (j - 1 >= 0 && board[i][j-1] == '.')
                    board[i][--j] = alpha++;
                break;
            case 1: /* move right */
                if (i + 1 < 10 && board[i+1][j] == '.')
                    board[++i][j] = alpha++;
                break;
            case 0: /* move left */
                if (i - 1 >= 0 && board[i-1][j] == '.')
                    board[--i][j] = alpha++;
                break;
        }
    } while (i < 10 && j < 10 && alpha <= 90);
    
    for (i = 0; i < BOARD_WIDTH; i++) {
        for (j = 0; j < BOARD_HEIGHT; j++)
            printf("%3c", board[i][j]);
        printf("\n");
    }

    return 0;
}