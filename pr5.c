#include <stdio.h>

void countingSort(int arr[], int n) {
    int i, max = arr[0];

    for(i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }

    int count[100] = {0}, output[100];

    for(i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for(i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for(i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
