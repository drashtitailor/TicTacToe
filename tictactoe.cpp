#include <iostream>

using namespace std;

// Function prototypes

void showBoard(char, char, char, char, char, char, char, char, char);
void makePlayerMove(char &, char &, char &, char &, char &, char &, char &, char &, char &, char);
bool checkWin(char, char, char, char, char, char, char, char, char);

int main()
{
    // Variables representing board
    char a1 = '1', a2 = '2', a3 = '3', b1 = '4', b2 = '5', b3 = '6', c1 = '7', c2 = '8', c3 = '9', p1Token = 'X', p2Token = 'O';
    
    int moves = 0; // Tracks move to ensure while loop breaks
    
    // While no player has won, each player makes a move. If nine moves are made, the game ends

    while(checkWin(a1, a2, a3, b1, b2, b3, c1, c2, c3) == false) {
        showBoard(a1, a2, a3, b1, b2, b3, c1, c2, c3);
        makePlayerMove(a1, a2, a3, b1, b2, b3, c1, c2, c3, p1Token);
        moves++;
        if(moves == 9 || checkWin(a1, a2, a3, b1, b2, b3, c1, c2, c3)) {
            break;
        }
        showBoard(a1, a2, a3, b1, b2, b3, c1, c2, c3);
        makePlayerMove(a1, a2, a3, b1, b2, b3, c1, c2, c3, p2Token);
        moves++;
    }
    
    showBoard(a1, a2, a3, b1, b2, b3, c1, c2, c3);
    if(checkWin(a1, a2, a3, b1, b2, b3, c1, c2, c3) == false) {
        cout << endl << "Draw" << endl;
    }
    else
        cout << endl << "Win" << endl;

    return 0;
}

// makePlayerMove allows the current player to make a move by accessing the board by reference

void makePlayerMove(char &a1, char &a2, char &a3, char &b1, char &b2, char &b3, char &c1, char &c2, char &c3, char token){
    
    bool validMove = false;
    int choice;
    
    do {
        cout << "Where do you want to place your token?" << endl;
        cin >> choice;
    
        switch(choice) {
            case 1: if(a1 != 'X' && a1 != 'O') {
                a1 = token;
                validMove = true;
            }
            break;
            case 2: if(a2 != 'X' && a2 != 'O') {
                a2 = token;
                validMove = true;
            }
            break;
            case 3: if(a3 != 'X' && a3 != 'O') {
                a3 = token;
                validMove = true;
            }
            break;
            case 4: if(b1 != 'X' && b1 != 'O') {
                b1 = token;
                validMove = true;
            }
            break;
            case 5: if(b2 != 'X' && b2 != 'O') {
                b2 = token;
                validMove = true;
            }
            break;
            case 6: if(b3 != 'X' && b3 != 'O') {
                b3 = token;
                validMove = true;
            }
            break;
            case 7: if(c1 != 'X' && c1 != 'O') {
                c1 = token;
                validMove = true;
            }
            break;
            case 8: if(c2 != 'X' && c2 != 'O') {
                c2 = token;
                validMove = true;
            }
            break;
            case 9: if(c3 != 'X' && c3 != 'O') {
                c3 = token;
                validMove = true;
            }
            break;
        }
    } while(validMove == false);
    
}

// checkWin takes a board as input and returns true if a win is detected

bool checkWin(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3){

    if((a1 == 'X' || a1 == 'O') && ((a1 == a2) && (a2 == a3))) {
        return true;
    }
    else if((b1 == 'X' || b1 == 'O') && ((b1 == b2) && (b2 == b3))) {
        return true;
    }
    else if((c1 == 'X' || c1 == 'O') && ((c1 == c2) && (c2 == c3))) {
        return true;
    }
    else if((a1 == 'X' || a1 == 'O') && ((a1 == b1) && (b1 == c1))) {
        return true;
    }
    else if((a2 == 'X' || a2 == 'O') && ((a2 == b2) && (b2 == c2))) {
        return true;
    }
    else if((a3 == 'X' || a3 == 'O') && ((a3 == b3) && (b3 == c3))) {
        return true;
    }
    else if((a1 == 'X' || a1 == 'O') && ((a1 == b2) && (b2 == c3))) {
        return true;
    }
    else if((a3 == 'X' || a3 == 'O') && ((a3 == b2) && (b2 == c1))) {
        return true;
    }
    else
        return false;
}

// showBoard takes a series of variables representing the board and prints them out in a tic tac toe format

void showBoard(char a1, char a2, char a3, char b1, char b2, char b3, char c1, char c2, char c3){
    cout << endl;
    cout << " " << a1 << " | " << a2 << " | " << a3 << endl;
    cout <<"-----------" << endl;
    cout << " " << b1 << " | " << b2 << " | " << b3 << endl;
    cout <<"-----------" << endl;
    cout << " " << c1 << " | " << c2 << " | " << c3 << endl;
    cout << endl;
}

