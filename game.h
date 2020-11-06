//
// Created by marwan on 4/27/20.
//
#include <iostream>
#include <stdlib.h>
#include <time.h>
#ifndef XO_GAME_H
#define XO_GAME_H


class game {
    char arr[3][3];
    int visited = 0;

    char checkRows() const;       //utility & predicate function
    char checkCols() const;       //utility & predicate function
    char checkFirDiag() const;    //utility & predicate function
    char checkSecDiag() const;    //utility & predicate function
public:
    game();

    void clear();

    void first();

    void view() const;

    char winner() const;          //predicate function
    bool fail() const;            //predicate function
    bool player(int &, const char &);

    void computer(const char &);

};


#endif //XO_GAME_H
