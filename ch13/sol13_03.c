/* Deals a random hand of cards */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void)
{
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char *rank_code[] = {"Two of", "Three of", "Four of", "Five of", "Six of", "Seven of",
                               "Eight of", "Nine of", "Ten of", "Jack of", "Queen of", "King of",
                               "Ace of"};
    const char *suit_code[] = {" clubs", " diamonds", " hearts", " spades"};

    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand: \n");
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS;     /* picks a random suit */
        rank = rand() % NUM_RANKS;     /* picks a random rank */
        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;
            printf("%s%s\n", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");

    return 0;
}