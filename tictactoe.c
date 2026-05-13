#include <stdio.h>

void playTicTacToe();
char tictactoe(char name1[], char name2[], int player);
void printBoard(char board[3][3]);
char declareWinner(char board[3][3]);

int main() {
    playTicTacToe();
    return 0;
}

void playTicTacToe() {

    printf("Welcome to Tic Tac Toe\n");

    char name1[50], name2[50];

    printf("Enter Your Names (space separated): ");
    scanf("%49s %49s", name1, name2);

    printf("Hello %s and %s!\n", name1, name2);
    printf("%s is X and %s is O\n", name1, name2);

    int player;

    printf("Who will go first?\n");
    printf("Enter 1 for %s or 2 for %s: ", name1, name2);
    
    if (scanf("%d", &player) != 1 || (player != 1 && player != 2)) {
        
        printf("Invalid choice! Defaulting to Player 1.\n");
        
        player = 1;
        
        while (getchar() != '\n');
    }
    
    
    char playAgain = 'y';

    do {

        int starter = player;

        char result = tictactoe(name1, name2, player);

        if (result == 'X') {
            player = 2;
        }
        else if (result == 'O') {
            player = 1;
        }
        else if(result == 'D') {
            player = (starter == 1) ? 2 : 1;
        }else if(result == 'E') {
            break;
        }else {
            printf("Unexpected result!\n");
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

    } while(playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
}

void printBoard(char board[3][3]) {
    printf("\n");

    printf("-------------\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("| %c ", board[i][j]);
        }

        printf("|\n");
        printf("-------------\n");
    }

    printf("\n");
}

char declareWinner(char board[3][3]) {

    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' &&
            board[i][0] == board[i][1] &&
            board[i][1] == board[i][2]) {

            return board[i][0];
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' &&
            board[0][j] == board[1][j] &&
            board[1][j] == board[2][j]) {

            return board[0][j];
        }
    }

    // Check diagonal 1
    if (board[0][0] != ' ' &&
        board[0][0] == board[1][1] &&
        board[1][1] == board[2][2]) {

        return board[0][0];
    }

    // Check diagonal 2
    if (board[0][2] != ' ' &&
        board[0][2] == board[1][1] &&
        board[1][1] == board[2][0]) {

        return board[0][2];
    }

    return ' '; // No winner
}

char tictactoe(char name1[], char name2[], int player) {

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col;
    int turn = 0;

    char winner = ' ';

    printBoard(board);

    printf("Enter 0 0 to exit the game.\n");

    while (turn < 9 && winner == ' ') {

        if (player == 1) {
            printf("%s (X), enter your move (row col): ", name1);
        }
        else {
            printf("%s (O), enter your move (row col): ", name2);
        }

        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input! Please enter numbers only.\n");
            while (getchar() != '\n');
            continue;
        }

        if (row == 0 || col == 0) {
            printf("Game exited.\n");
            return 'E';
        }

        row--;
        col--;

        if (row < 0 || row > 2 ||
            col < 0 || col > 2 ||
            board[row][col] != ' ') {

            printf("Invalid move! Try again.\n");
            continue;
        }

        // Place symbol
        if (player == 1) {
            board[row][col] = 'X';
        }
        else {
            board[row][col] = 'O';
        }

        turn++;

        printBoard(board);

        // Check winner
        winner = declareWinner(board);

        // Switch player
        if (winner == ' ') {
            player = (player == 1) ? 2 : 1;
        }
    }

    // Final result
    if (winner == 'X') {
        printf("%s wins! 🎉\n", name1);
        return 'X';
    }
    else if (winner == 'O') {
        printf("%s wins! 🎉\n", name2);
        return 'O';
    }
    else {
        printf("It's a draw!\n");
        return 'D';
    }
}