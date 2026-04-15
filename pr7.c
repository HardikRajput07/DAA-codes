#include <stdio.h>

int main() {
    int coins[] = {100, 50, 20, 10, 5, 2, 1};
    int n = 7, amount, i;

    printf("Making Change\n");

    printf("Enter amount: ");
    scanf("%d", &amount);

    printf("\nCoins used:\n");

    for(i = 0; i < n; i++) {
        if(amount >= coins[i]) {
            printf("%d -> %d\n", coins[i], amount / coins[i]);
            amount = amount % coins[i];
        }
    }

    return 0;
}
