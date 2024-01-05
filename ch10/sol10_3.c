/* Classifies a poker hand */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs; /* can be 0, 1, 2 */

/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);
void selection_sort(int low, int high);
int split(int low, int high);

/**********************************************************
 * main: Calls read_cards, analyze_hand, and print_result *
 *       repeatedly.                                      *
 **********************************************************/
int main(void)
{
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}

/**********************************************************
 * read_cards: Reads cards into external variable hand;   *
 *             checks for bad cards and duplicate cards.  *
 **********************************************************/
void read_cards()
{
    char ch, rank_ch, suit_ch;
    int rank, suit, i;
    bool bad_card, duplicate_card;
    int cards_read = 0;

    while (cards_read < NUM_CARDS) {
        bad_card = false;
        duplicate_card = false;

        printf("Enter a card: ");

        rank_ch = getchar();
        switch (rank_ch) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0; break;
            case '3':           rank = 1; break;
            case '4':           rank = 2; break;
            case '5':           rank = 3; break;
            case '6':           rank = 4; break;
            case '7':           rank = 5; break;
            case '8':           rank = 6; break;
            case '9':           rank = 7; break;
            case 't': case 'T': rank = 8; break;
            case 'j': case 'J': rank = 9; break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }

        suit_ch = getchar();
        switch (suit_ch) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;
        }

        while ((ch = getchar()) != '\n')
            if (ch != ' ') bad_card = true;

        for (i = 0; i < cards_read; i++) {
            if (rank == hand[i][0] && suit == hand[i][1])
                duplicate_card = true;
        }
    
        if (bad_card)
            printf("Bad card; ignored.\n");
        else if (duplicate_card)
            printf("Duplicate card; ignored.\n");
        else {
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }
}

/**********************************************************
 * analyze_hand: Determines whether the hand contains a   *
 *               straight, a flush, four-of-a-kind,       *
 *               and/or three-of-a-kind; determines the   *
 *               number of pairs; stores the result into  *
 *               external variables straight, flush,      *
 *               four, three, and pairs.                  *
 **********************************************************/
void analyze_hand()
{
    int i, num_consec = 0;
    straight = true;
    flush = true;
    four = false;
    three = false;
    pairs = 0;

    /* check for flush */
    for (i = 1; i < NUM_CARDS; i++) {
        if (hand[i][1] != hand[i - 1][1])
            flush = false;
    }

    /* sort hand in ascending order by rank */
    selection_sort(0, NUM_CARDS - 1);

    /* check for straight */
    for (i = 1; i < NUM_CARDS; i++) {
        if ((hand[i][0] - hand[i - 1][0]) > 1)
            straight = false;
    }

    /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
    for (i = 1; i < NUM_CARDS; i++) {
        if ((hand[i][0] - hand[i - 1][0]) == 0) {
            num_consec++;

            if (num_consec == 1) pairs++;
            if (num_consec == 2) three = true;
            if (num_consec == 3) four = true;
        } else 
            num_consec = 0;
    }
}

/**********************************************************
 * print_result: Prints the classification of the hand,   *
 *               based on the values of the external      *
 *               variables straight, flush, four, three,  *
 *               and pairs.                               *
 **********************************************************/
void print_result(void)
{
    if (straight && flush) printf("Straight flush");
    else if (four)         printf("Four of a kind");
    else if (three &&
             pairs == 1)   printf("Full house");
    else if (flush)        printf("Flush");
    else if (straight)     printf("Straight");
    else if (three)        printf("Three of a kind");
    else if (pairs == 2)   printf("Two pairs");
    else if (pairs == 1)   printf("Pair");
    else                   printf("High card");

    printf("\n\n");
}

void selection_sort(int low, int high)
{
    int sorted;

    if (low >= high) return;
    sorted = split(low, high);
    selection_sort(low, sorted - 1);
}

int split(int low, int high)
{
    int max_rank = hand[high][0];
    int max_suit = hand[high][1];

    for (;;) {
        if (low < high && hand[low][0] <= max_rank)
            low++;
        if (low >= high) break;
        if (hand[low][0] > max_rank) {
            hand[high][0] = hand[low][0];
            hand[high][1] = hand[low][1];
            hand[low][0] = max_rank;
            hand[low][1] = max_suit;
            max_rank = hand[high][0];
            max_suit = hand[high][1];
            low++;
        }
    }

    return high;
}