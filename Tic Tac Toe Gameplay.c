#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1)
                printf("|");
        }
        printf("\n");
        if (i < SIZE - 1)
            printf("---|---|---\n");
    }
    printf("\n");
}
int checkWinner(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }
    return 0;
}
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}
void computerMove(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                return;
            }
        }
    }
}
int main() {
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int mode;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Choose game mode:\n");
    printf("1. Player vs Player\n");
    printf("2. Player vs Computer\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &mode);
    if (mode != 1 && mode != 2) {
        printf("Invalid choice. Exiting the game.\n");
        return 0;
    }
    char player = 'X';
    int row, col;
    while (1) {
        displayBoard(board);
        if (player == 'X' || (mode == 1 && player == 'O')) {
            printf("Player %c's turn. Enter your move (row and column): ", player);
            scanf("%d %d", &row, &col);
            row--; col--;
            if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
                printf("Invalid move! Try again.\n");
                continue;
            }
            board[row][col] = player;
        } else {
            printf("Computer's turn...\n");
            computerMove(board);
        }
        if (checkWinner(board, player)) {
            displayBoard(board);
            if (mode == 2 && player == 'O') {
                printf("Computer wins! Better luck next time.\n");
            } else {
                printf("Player %c wins! Congratulations!\n", player);
            }
            break;
        }
        if (isBoardFull(board)) {
            displayBoard(board);
            printf("It's a tie! Well played!\n");
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}
