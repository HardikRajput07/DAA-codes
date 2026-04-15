#include <stdio.h>

// Function using iteration
int fibIterative(int n) {
    int a = 0, b = 1, c;

    if (n == 0)
        return a;
    if (n == 1)
        return b;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Function using recursion
int fibRecursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Nth Fibonacci number using iteration = %d\n", fibIterative(n));
    printf("Nth Fibonacci number using recursion = %d\n", fibRecursive(n));

    return 0;
}
