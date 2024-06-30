#include <iostream>
#include <vector>
using namespace std;
void displayBoard(const vector<vector<char>>& board) {
    cout << "Current Board:\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}
char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}
int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;
    while (true) {
        displayBoard(board);
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }
        board[row][col] = currentPlayer;
        gameWon = checkWin(board, currentPlayer);
        if (gameWon) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        gameDraw = checkDraw(board);
        if (gameDraw) {
            displayBoard(board);
            cout << "The game is a draw!\n";
            break;
        }
        currentPlayer = switchPlayer(currentPlayer);
    }
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        main();
    }
    return 0;
}
