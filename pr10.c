#include <stdio.h>

int board[20], count = 0;

int place(int row, int col) {
    int i;
    for(i = 1; i < row; i++) {
        if(board[i] == col || 
           board[i] - i == col - row || 
           board[i] + i == col + row) {
            return 0;
        }
    }
    return 1;
}

void solve(int row, int n) {
    int col;
    for(col = 1; col <= n; col++) {
        if(place(row, col)) {
            board[row] = col;
            if(row == n) {
                count++;
                printf("Solution %d: ", count);
                for(int i = 1; i <= n; i++) {
                    printf("%d ", board[i]);
                }
                printf("\n");
            } else {
                solve(row + 1, n);
            }
        }
    }
}

int main() {
    int n;

    printf("N-Queens Problem\n");
    printf("Enter value of N: ");
    scanf("%d", &n);

    solve(1, n);

    if(count == 0)
        printf("No solution\n");

    return 0;
}
