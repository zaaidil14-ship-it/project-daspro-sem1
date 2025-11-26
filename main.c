//project akhir

#include <stdio.h>
#define PLAYER 'X'
#define AI 'O'

// --- Fungsi Menampilkan Papan ---
void displayBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n");
}

// --- Mengecek Kemenangan ---
int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

// --- Mengecek Seri ---
int isDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != PLAYER && board[i][j] != AI)
                return 0;
    return 1;
}

// --- Gerakan Pemain ---
void playerMove(char board[3][3]) {
    int choice;
    int row, col;

    while (1) {
        printf("Pilih posisi (1-9): ");
        scanf("%d", &choice);

        if (choice < 1 || choice > 9) {
            printf("Pilihan tidak valid! Coba lagi.\n");
            continue;
        }

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (board[row][col] != PLAYER && board[row][col] != AI) {
            board[row][col] = PLAYER;
            break;
        } else {
            printf("Posisi sudah terisi! Coba lagi.\n");
        }
    }
}




