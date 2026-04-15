#include <stdio.h>

int main() {
    int n, i, j, capacity, temp;
    int value[100], weight[100];
    float ratio[100], profit = 0;

    printf("Fractional Knapsack\n");

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter profit and weight:\n");
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

    printf("\nItems selected:\n");

    for(i = 0; i < n; i++) {
        if(capacity >= weight[i]) {
            printf("Item %d fully\n", i + 1);
            profit += value[i];
            capacity -= weight[i];
        } else {
            printf("Item %d partially\n", i + 1);
            profit += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", profit);

    return 0;
}
