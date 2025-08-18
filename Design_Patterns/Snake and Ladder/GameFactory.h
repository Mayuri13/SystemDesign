#ifndef GAME_FACTORY_H
#define GAME_FACTORY_H
#include "Game.h"
#include "./utilities/GameType.h"
#include "./interface/Rules.h"
#include "./standardRules.h"

class GameFactory {
    public:
        static Game* createGame(GameType gt){
            if(gt == GameType::STANDARD){
                return new Game(new standardRules());
            }
            return nullptr;
        }
};

#endif