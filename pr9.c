//01
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity, i, w;
    int weight[100], value[100];
    int dp[100][100];

    printf("0/1 Knapsack (DP)\n");

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for(i = 1; i <= n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter values:\n");
    for(i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    for(i = 0; i <= n; i++) {
        for(w = 0; w <= capacity; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(weight[i] <= w)
                dp[i][w] = max(value[i] + dp[i - 1][w - weight[i]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("\nMaximum profit = %d\n", dp[n][capacity]);

    return 0;
}

//fractional

#include <stdio.h>

int main() {
    int n, i, j, capacity, temp;
    int value[100], weight[100];
    float ratio[100], profit = 0;

    printf("Fractional Knapsack\n");

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter value and weight:\n");
    for(i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &value[i], &weight[i]);
        ratio[i] = (float)value[i] / weight[i];
    }

    printf("Enter capacity: ");
    scanf("%d", &capacity);

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(ratio[i] < ratio[j]) {
                temp = value[i];
                value[i] = value[j];
                value[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                float t = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = t;
            }
        }
    }

    for(i = 0; i < n; i++) {
        if(capacity >= weight[i]) {
            profit += value[i];
            capacity -= weight[i];
        } else {
            profit += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", profit);

    return 0;
}
