#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int roll_dice(void);
bool play_game(void);

int main(void)
{
    bool result;
    int won = 0, loss = 0;
    char command;

    for (;;) {
        result = play_game();

        printf("\n");
        
        if (result) {
            won++;
            printf("You win!\n");
        } else if (!result) {
            loss++;
            printf("You lose!\n");
        }

        printf("\nPlay again? ");
        scanf("%c", &command);

        if (command != 'y' && command != 'Y')
            break;
    }

    printf("\nWins: %d  Losses: %d\n", won, loss);

    return 0;
}

int roll_dice(void)
{
    int dice1, dice2;

    dice1 = (rand() % 6) + 1;
    dice2 = (rand() % 6) + 1;

    return dice1 + dice2;
}

bool play_game(void)
{
    int sum, point;

    sum = roll_dice();

    printf("You rolled: %d\n", sum);
    if (sum == 7 || sum == 11)
        return true;
    else if (sum == 2 || sum == 3 || sum == 12)
        return false;
    else 
        point = sum;
        printf("Your point is %d\n", point);

    do {
        sum = roll_dice();
        printf("You rolled: %d\n", sum);
        if (sum == point)
            return true;
    } while (sum != 7);

    return false;
}