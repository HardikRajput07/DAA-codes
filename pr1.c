#include <stdio.h>

// Function using loop
int sumLoop(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

// Function using equation
int sumEquation(int n) {
    return (n * (n + 1)) / 2;
}

// Function using recursion
int sumRecursion(int n) {
    if (n == 0)
        return 0;
    else
        return n + sumRecursion(n - 1);
}

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Sum using loop = %d\n", sumLoop(n));
    printf("Sum using equation = %d\n", sumEquation(n));
    printf("Sum using recursion = %d\n", sumRecursion(n));

    return 0;
}
