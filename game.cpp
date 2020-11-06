//
// Created by marwan on 4/27/20.
//

#include "game.h"

using namespace std;
#define  lp(i, n)     for(int i=0;i<n;i++)
#define loop(i, x, n)   for(int i=x ; i<=n;i++)
#define  back(i, n)     for(int i=n-1;i>=0;i--)


game::game() {
    clear();
}

void game::clear() {
    visited = 0;
    lp(i, 3) {
        lp(r, 3) arr[i][r] = ' ';
    }
}

void game::first() {
    int n = 0;
    lp(i, 3) {
        cout << "\t\t|";
        lp(r, 3) cout << ' ' << ++n << " |", arr[i][r] = ' ';
        cout << "\n\t\t-------------\n";
    }
    cout << "WARNING !!: The player have to enter the number of cell which he want to insert this symbol in it.\n\n";
}

void game::view() const {
    lp(i, 3) {
        cout << "\t\t|";
        lp(r, 3) cout << ' ' << arr[i][r] << " |";
        cout << "\n\t\t-------------\n";
    }
}

char game::checkRows() const {
    bool cond;
    lp(i, 3) {
        char temp = arr[i][0];
        cond = true;
        lp(r, 3) {
            if (temp == ' ' || arr[i][r] != temp) {
                cond = false;
                break;
            }
        }
        if (cond)
            return temp;
    }
    return '-';
}

char game::checkCols() const {
    bool cond;
    lp(r, 3) {
        char temp = arr[0][r];
        cond = true;
        lp(i, 3) {
            if (temp == ' ' || arr[i][r] != temp) {
                cond = false;
                break;
            }
        }
        if (cond)
            return temp;
    }
    return '-';
}

char game::checkFirDiag() const {
    bool cond = true;
    char temp = arr[0][0];
    int j = 0;
    lp(i, 3) {
        if (temp == ' ' || arr[i][j] != temp) {
            cond = false;
            break;
        }
        j++;
    }
    if (cond)
        return temp;
    return '-';
}

char game::checkSecDiag() const {
    bool cond = true;
    char temp = arr[0][2];
    int j = 2;
    lp(i, 3) {
        if (temp == ' ' || arr[i][j] != temp) {
            cond = false;
            break;
        }
        j--;
    }
    if (cond)
        return temp;
    return '-';
}

char game::winner() const {
    if (visited > 2) {
        char temp = checkCols();
        if (temp != '-')
            return temp;
        temp = checkRows();
        if (temp != '-')
            return temp;
        temp = checkFirDiag();
        if (temp != '-')
            return temp;
        temp = checkSecDiag();
        if (temp != '-')
            return temp;
    }
    return '-';
}

bool game::fail() const {
    if (visited > 6) {
        if (checkSecDiag() == '-' && checkFirDiag() == '-'
            && checkRows() == '-' && checkCols() == '-')
            return true;
    }
    return false;
}

bool game::player(int &n, const char &c) {
    if (n <= 0 || n > 9) return false;
    n--;
    if (arr[n / 3][n % 3] != ' ')
        return false;
    else
        arr[n / 3][n % 3] = c, visited++;
    return true;
}

void game::computer(const char &c) {
    int n ;
    n = rand() % 9;
    while (arr[n / 3][n % 3] != ' ')
        n = rand() % 9;
    arr[n / 3][n % 3] = c;
    visited++;
}