/* Calculates a broker's commission */

#include <stdio.h>

int main(void) 
{
    int numberShare;
    float priceShare, value, commission, rivalCommission;

    printf("Enter number of shares: ");
    scanf("%d", &numberShare);
    printf("Enter price per share: ");
    scanf("%f", &priceShare);

    value = numberShare * priceShare;

    if (value < 2500.00f)
        commission = 30.00f + 0.17f * value;
    else if (value >= 2500.00f && value < 6250.00f)
        commission = 56.00f + .0066f * value;
    else if (value >= 6250.00f && value < 20000.00f)
        commission = 76.00f + .0034f * value;
    else if (value >= 20000.00f && value < 50000.00f)
        commission = 100.00f + .0022f * value;
    else if (value >= 50000.00f && value < 500000.00f)
        commission = 155.00f + .0011f * value;
    else 
        commission = 255.00f + .009f * value;
    
    if (commission < 39.00f)
        commission = 39.00f;

    if (numberShare < 2000)
        rivalCommission = 33.00f + 0.03f * numberShare;
    else if (numberShare >= 2000)
        rivalCommission = 33.00f + 0.02f * numberShare;
    
    printf("Commission: $%.2f\n", commission);
    printf("Rival broker commission: $%.2f\n", rivalCommission);

    return 0;
}