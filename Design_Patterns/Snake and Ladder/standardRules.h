#ifndef STANDARD_RULES_H
#define STANDARD_RULES_H
#include "./interface/Rules.h"
#include "./Board.h"
#include "./Player.h"
#include <bits/stdc++.h>
using namespace std;

class standardRules : public Rules{
public:
    standardRules(){
        // Seed random number generator once
        srand(time(0));
    }
    
    int roleDice() {
        return (rand() % 6) + 1;
    }

    bool checkWin(int score) {
        if(score == 100)
            return true;
        return false;
    }
    bool checkSnake(Board* board, Player* player, int score) {
        int updatedScore = board->isSnake(score);
        if(updatedScore > 0){
            player->updateScore(updatedScore);
            return true;
        }
        return false;   
    }
    bool checkLadder(Board* board, Player* player, int score) {
        int updatedScore = board->isLadder(score);
        if(updatedScore > 0){
            player->updateScore(updatedScore);
            return true;
        }
        return false; 
    }
    bool isValidScore(Board* board, Player* player, int score) {
        if(score > 100)
            return false;
        player->updateScore(score);
        return true;
    }
};

#endif