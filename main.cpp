#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <sstream>
#include "game.h"


using namespace std;

bool checkInput(string &s)  {
    if (s.length()!=1)
        return false;
    if(s[0]=='0')
        return false;
    if(isdigit(s[0]))
        return true;
}

int convertToInt(string &s){
    return s[0]-'0';
}

bool win(const game &xo) {
    if (xo.winner() != '-') {
        if (xo.winner() == 'X')
            xo.view(), cout << "\n\t\tYOU ARE THE WINNER ! ! !\n\n";
        else
            xo.view(), cout << "\n\t\tCOMPUTER IS THE WINNER ! ! !\n\n";
        return true;
    }
    return false;
}

bool noWin(const game &xo) {
    if (xo.fail()) {
        xo.view(), cout << "\n\t\t\tNO WIN     :(\n";
        return true;
    }
    return false;
}

void play() {

    string choice = "yes";
    while (choice == "yes") {
        game xo;
        xo.first();
        while (true) {
            xo.view();
            string cell;
            cout << "Please enter a valid number: ";
            cin >> cell;
            while (!checkInput(cell)) {
                cout << "Please enter a valid choice: ";
                cin >> cell;
            }
            int cellInt=convertToInt(cell);
            while(!xo.player(cellInt, 'X')){
                cout<<"This cell is not empty, please enter a number of an empty cell: ";
                cin >> cell;
                while (!checkInput(cell)) {
                    cout << "Please enter a valid choice: ";
                    cin >> cell;
                }
                cellInt=convertToInt(cell);
            }
            if (win(xo))
                break;
            xo.computer('O');
            if (win(xo))
                break;
            if (noWin(xo))
                break;
        }
        cout << "Do you want to play again?\n";
        cin >> choice;
    }
}

int main() {
    srand(time(NULL));
    play();
}
