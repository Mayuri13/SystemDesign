#ifndef PLAYER_H
#define PLAYER_H
#include <bits/stdc++.h>
using namespace std;

class Player {
    string name;
    int id;
    int score;
public:
    Player(int id, string name){
        this->id = id;
        this->name = name;
        score = 0;
    }

    string getName(){
        return name;
    }

    int getScore(){
        return score;
    }

    void updateScore(int value){
        score = value;
    }
};

#endif