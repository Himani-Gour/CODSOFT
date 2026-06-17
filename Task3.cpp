#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard() {
    cout << "\n";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char p) {
    for(int i=0;i<3;i++) {
        if(board[i][0]==p && board[i][1]==p && board[i][2]==p)
            return true;

        if(board[0][i]==p && board[1][i]==p && board[2][i]==p)
            return true;
    }

    if(board[0][0]==p && board[1][1]==p && board[2][2]==p)
        return true;

    if(board[0][2]==p && board[1][1]==p && board[2][0]==p)
        return true;

    return false;
}

int main() {
    char player='X';
    int move;

    for(int turn=0; turn<9; turn++) {
        displayBoard();

        cout << "Player " << player << " enter position: ";
        cin >> move;

        int row=(move-1)/3;
        int col=(move-1)%3;

        if(board[row][col]=='X' || board[row][col]=='O') {
            cout << "Position already taken!\n";
            turn--;
            continue;
        }

        board[row][col]=player;

        if(checkWin(player)) {
            displayBoard();
            cout << "Player " << player << " wins!\n";
            return 0;
        }

        player=(player=='X')?'O':'X';
    }

    displayBoard();
    cout << "Game Draw!\n";

    return 0;
}