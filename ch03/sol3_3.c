/* Takes ISBN-13 as input and outputs its sections */

#include <stdio.h>

int main(void)
{
    int gs1_prefix, group_id, pub_code, item_no, check;

    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1_prefix, &group_id, &pub_code, &item_no, &check);

    printf("GS1 prefix: %d\n", gs1_prefix);
    printf("Group identifier: %d\n", group_id);
    printf("Publisher code: %d\n", pub_code);
    printf("Item number: %d\n", item_no);
    printf("Check digit: %d\n", check);

    return 0; 
}