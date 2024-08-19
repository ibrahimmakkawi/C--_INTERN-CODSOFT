#include <iostream>
#include <cctype>   // Includes the library for character handling functions

using namespace std;

// Function to draw the board
void displayBoard(char Game[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << Game[i][j];
            if(j < 2) cout << "|"; // Print a separator for columns
        }
        cout << endl;
        if(i < 2) cout << "-----" << endl; // Print a separator for rows
    }
}

// Function to update the board with the player's move
bool makeMove(char Game[3][3], int step, char player) {
    int row = (step - 1) / 3;
    int col = (step - 1) % 3;

    if(Game[row][col] == 'X' || Game[row][col] == 'O') {
        cout << "This spot is already taken! Choose another one." << endl;
        return false;
    } else {
        Game[row][col] = player;
        return true;
    }
}

// Function to check if there's a winner or a draw
int checkWin(char Game[3][3]) {
    // Check rows and columns
    for(int i = 0; i < 3; i++) {
        if(Game[i][0] == Game[i][1] && Game[i][1] == Game[i][2]) {
            if(Game[i][0] == 'X') return 1;
            if(Game[i][0] == 'O') return 2;
        }
        if(Game[0][i] == Game[1][i] && Game[1][i] == Game[2][i]) {
            if(Game[0][i] == 'X') return 1;
            if(Game[0][i] == 'O') return 2;
        }
    }
    // Check diagonals
    if(Game[0][0] == Game[1][1] && Game[1][1] == Game[2][2]) {
        if(Game[0][0] == 'X') return 1;
        if(Game[0][0] == 'O') return 2;
    }
    if(Game[0][2] == Game[1][1] && Game[1][1] == Game[2][0]) {
        if(Game[0][2] == 'X') return 1;
        if(Game[0][2] == 'O') return 2;
    }
    // Check for draw
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(Game[i][j] != 'X' && Game[i][j] != 'O')
                return 0; // Game still ongoing
    return 3; // Draw
}

int main() {
    char P1, P2;
    int again = 1;
    int result = 0;
    int step = 0;
    char Game[3][3];

    while(again == 1) {
        cout << "Welcome to Tic Tac Toe" << endl;
        cout << "First choose X or O" << endl;
        cin >> P1;

        while(P1 != 'x' && P1 != 'X' && P1 != 'o' && P1 != 'O') {
            cout << "Only X or O: ";
            cin >> P1;
        }

        P1 = toupper(P1); 
        P2 = (P1 == 'X') ? 'O' : 'X';
        cout << "First player is: " << P1 << endl << "Second player is: " << P2 << endl << endl;

        // Initialize the game board
        int k = 1;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                Game[i][j] = k + '0';
                k++;
            }
        }

        result = 0;
        int turn = 1; // 1 for P1's turn, 2 for P2's turn
        while(result == 0) {
            displayBoard(Game);
            cout << "Player " << (turn == 1 ? P1 : P2) << ", enter your move (1-9): ";
            cin >> step;

            // Validate input
            if(cin.fail() || step < 1 || step > 9) {
                cout << "Invalid input! Please enter a number between 1 and 9." << endl;
                cin.clear(); // Clear the error flag
                cin.ignore(1000, '\n'); // Discard invalid input
                continue;
            }

            // Ensure move is valid
            if(!makeMove(Game, step, (turn == 1) ? P1 : P2)) {
                continue;
            }

            result = checkWin(Game);

            if(result == 1) {
                displayBoard(Game);
                cout << "Player X wins! Congratulations!" << endl;
            } else if(result == 2) {
                displayBoard(Game);
                cout << "Player O wins! Congratulations!" << endl;
            } else if(result == 3) {
                displayBoard(Game);
                cout << "It's a draw! Well played!" << endl;
            }

            turn = (turn == 1) ? 2 : 1; // Switch player
        }

        cout << "Do you want to play again? Enter 1 for Yes, 0 for No: ";
        cin >> again;
    }

    return 0;
}
