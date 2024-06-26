#include <stdio.h>
#include <string.h>

#define MAX_N 10

void print_board(char board[][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_safe(char board[][MAX_N], int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return 0; // same column
        if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return 0; // upper left diagonal
        if (col + (row - i) < n && board[i][col + (row - i)] == 'Q') return 0; // upper right diagonal
    }
    return 1;
}

void solve_n_queens(char board[][MAX_N], int row, int n, int *solutions) {
    if (row == n) {
        print_board(board, n);
        (*solutions)++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (is_safe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve_n_queens(board, row + 1, n, solutions);
            board[row][col] = '.'; // reset
        }
    }
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    char board[MAX_N][MAX_N];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = '.'; // initialize with empty spaces
        }
    }

    int solutions = 0;
    solve_n_queens(board, 0, n, &solutions);

    printf("Total solutions: %d\n", solutions);

    return 0;
}