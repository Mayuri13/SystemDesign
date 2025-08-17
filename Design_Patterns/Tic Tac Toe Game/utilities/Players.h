#ifndef PLAYERS_H
#define PLAYERS_H
#include "./Symbols.h"
#include <bits/stdc++.h>
using namespace std;

class Player{
    int id;
    string name;
    Symbol* symbol;
    int score;
public:
    Player(int Id, string name, Symbol* symbol){
        this->id = Id;
        this->name = name;
        this->symbol = symbol;
        score = 0;                 
    }

    int getId(){
        return id;
    }

    string getName(){
        return name;
    }

    Symbol* getSymbol(){
        return symbol;
    }

    int getScore(){
        return score;
    }

    void incrementScore(){
        score++;
    }

    // Desctructure for deleting used classes
    ~Player() {
        delete symbol;
    }

};

#endif