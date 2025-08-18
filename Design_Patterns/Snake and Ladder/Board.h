#ifndef BOARD_H
#define BOARD_H
#include "./Player.h"
#include "./interface/Rules.h"
#include <bits/stdc++.h>
using namespace std;

class Board {
    map<int, int>snake;
    map<int, int>ladder;
public:
    Board() {
        snake = {
            {62, 5},
            {33, 6},
            {49, 9},
            {88, 16},
            {41, 20},
            {56, 53},
            {98, 64},
            {93, 73},
            {95, 75}
        };

        ladder = {
            {2, 37},
            {27, 46},
            {10, 32},
            {51, 68},
            {61, 79},
            {65, 84},
            {71, 91},
            {81, 100},
        };
    }

    int isSnake(int score){
        if(snake.find(score) != snake.end())
            return snake[score];
        return 0;
    }

    int isLadder(int score){
        if(ladder.find(score) != ladder.end())
            return ladder[score];
        return 0;
    }
};

#endif