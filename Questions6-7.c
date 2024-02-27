#include <stdio.h>
#include <stdbool.h>
#include <limits.h>


// Question n°6

char boardGame[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};

char currentPlayer = 'X';

// Function to display the board
void ViewBoard(){
    int i, j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%c ", boardGame[i][j]);
        }
        printf("\n");
    }
}


// Function to check if there is a winner
bool IsWinner() {
    // Check lines and columns
    int i;
    for (i = 0; i < 3; ++i) {
        if ((boardGame[i][0] == boardGame[i][1] && boardGame[i][1] == boardGame[i][2]) ||
            (boardGame[0][i] == boardGame[1][i] && boardGame[1][i] == boardGame[2][i])) {
            return true;
        }
    }

    // Check diagonals
    if ((boardGame[0][0] == boardGame[1][1] && boardGame[1][1] == boardGame[2][2]) ||
        (boardGame[0][2] == boardGame[1][1] && boardGame[1][1] == boardGame[2][0])) {
        return true;
    }

    return false;
}


// Function to check if all the cases are fill and therefore there is no winner
bool NoWinner() {
    int i, j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            if (boardGame[i][j] != 'X' && boardGame[i][j] != 'O') {
                return false; 
            }
        }
    }
    return true; 
}




// Main function for tic-tac-toe game
void TicTacGame() {
    int move;
    int row, col;

    while (1) {
        ViewBoard();

        printf("Player %c, choose a movement (1-9): ", currentPlayer);
        scanf("%d", &move);

        // Position in the array
        row = (move - 1) / 3;
        col = (move - 1) % 3;

        // Check if the case is already filled or doesn't exist
        if (move < 1 || move > 9 || boardGame[row][col] == 'X' || boardGame[row][col] == 'O') {
            while ((getchar()) != '\n'); // Clear input buffer
            printf("Movement unavailable. Try again.\n");
            continue;
        }

        boardGame[row][col] = currentPlayer;

        if (IsWinner()) {
            ViewBoard();
            printf("Player %c wins the game!\n", currentPlayer);
            break;
        }
        
        if (NoWinner()) {
            printf("Nobody wins the game!\n");
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

// Question n°7 1)

void sieveOfEratosthenes(int n) {
    bool *isPrime = malloc((n + 1) * sizeof(bool)); 
    if (isPrime == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    int i, p;
    for (i = 0; i <= n; ++i) {
        isPrime[i] = true;
    }

    for (p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    printf("Prime numbers up to %d : ", n);
    for (i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(isPrime); 
}


// Question n°7 2)
void sieveOfEratosthenesOpti(int n) {
    int size = (n - 1) / 2;
    bool *isPrime = malloc((size + 1) * sizeof(bool)); 
    if (isPrime == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    int i, p;
    for (i = 0; i <= size; ++i) {
        isPrime[i] = true;
    }

    for (p = 3; p * p <= n; p += 2) {
        if (isPrime[p / 2]) {
            for (i = p * p; i <= n; i += p) {
                isPrime[i / 2] = false;
            }
        }
    }

    printf("Prime numbers up to %d : ", n);
    printf("2 ");
    for (i = 3; i <= n; i += 2) {
        if (isPrime[i / 2]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    free(isPrime); 
}


int main() {
    int choice;
    printf("Choose a program (6 for Tic-Tac-Toe, 7 for Sieve of Eratosthenes, 72 for Sieve of EratosthenesOpti): ");
    scanf("%d", &choice);

    if (choice == 6) {
        TicTacGame();
    } else if (choice == 7) {
        int N;
        printf("Enter a natural number N: ");
        scanf("%d", &N);

        sieveOfEratosthenes(N);    
        
    } 
    else if (choice == 72) {
        int N;
        printf("Enter a natural number N: ");
        scanf("%d", &N);

        sieveOfEratosthenesOpti(N);    
        
        
    } 
    else {
        printf("Invalid choice. Exiting program.\n");
    }

    return 0;
}

