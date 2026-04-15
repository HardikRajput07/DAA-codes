#include <stdio.h>

int minCoins(int coins[], int n, int amount) {
    int dp[1000];
    int i, j;

    for(i = 0; i <= amount; i++) {
        dp[i] = 100000;
    }

    dp[0] = 0;

    for(i = 1; i <= amount; i++) {
        for(j = 0; j < n; j++) {
            if(coins[j] <= i) {
                if(dp[i - coins[j]] + 1 < dp[i]) {
                    dp[i] = dp[i - coins[j]] + 1;
                }
            }
        }
    }

    if(dp[amount] == 100000)
        return -1;
    else
        return dp[amount];
}

int main() {
    int coins[100], n, amount, i;

    printf("Making Change (DP)\n");

    printf("Enter number of coins: ");
    scanf("%d", &n);

    printf("Enter coins:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    int result = minCoins(coins, n, amount);

    if(result == -1)
        printf("Not possible\n");
    else
        printf("Minimum coins needed = %d\n", result);

    return 0;
}
