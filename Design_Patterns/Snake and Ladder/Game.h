#ifndef GAME_H
#define GAME_H
#include <bits/stdc++.h>
#include "./Player.h"
#include "./Board.h"
#include "./interface/Rules.h"
using namespace std;

class Game {
    deque<Player*> players;
    bool isGameOver;
    Rules* rules;
    Board* board;
public:
    Game(Rules* rules){
        this->rules = rules;
        isGameOver = false;
        board = new Board();
    }

    void addPlayer(Player* player){
        players.push_back(player);
    }

    void play(){
        cout<<"Game Started! :) 🤩"<<endl;

        while(!isGameOver){
            Player* currPlayer = players.front();
            int diceValue = rules->roleDice(), currScore = currPlayer->getScore(); 
            int totalScore = diceValue + currScore;
            cout<<currPlayer->getName()<<" rolled "<<diceValue<<endl;

            if(rules->isValidScore(board, currPlayer, totalScore)){
                cout<<"🎲 "<<currPlayer->getName()<<"'s current score is "<<totalScore<<endl;
                if(rules->checkSnake(board, currPlayer, totalScore)){
                    cout<<"☹️ Oops you got a snake 🐍! Your score reduced to "<<currPlayer->getScore()<<endl;
                }
                else if(rules->checkLadder(board, currPlayer, totalScore)){
                    cout<<"🥳 Hurray you got a ladder 🪜! Your score increased to "<<currPlayer->getScore()<<endl;
                }
            }
            else{
                cout<<"👺 Need "<<(100-currScore)<<" to win!"<<endl;
            }
            
            if(rules->checkWin(currPlayer->getScore())){
                cout<<"🥳🥳🥳  Hurray!! "<<currPlayer->getName()<<" won the match! 🥳🥳🥳"<<endl;
                isGameOver = true;
                return;
            }

            players.pop_front();
            players.push_back(currPlayer);
        }
    }

    ~Game(){
        delete board;
        delete rules;
    }
};

#endif