#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H
#include "./utilities/GameType.h"
#include "./Game.h"

class GameFactory {
public:
//If game factory is Standard then create a Stnadard game
    static Game* createGame(Gametype gt, int boardSize){
        if(gt == Gametype::STANDARD)
            return new Game(boardSize);
        return nullptr;
    }
};

#endif