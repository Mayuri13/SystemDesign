#ifndef GAME_H
#define GAME_H
#include "./GameFactory.h"
#include "./utilities/Players.h"
#include <bits/stdc++.h>
#include "Board.h"
#include "./interfaces/Rules.h"
#include "./interfaces/IObserver.h"
#include "./standardRules.h"
using namespace std;

class Game {
    int boardSize;
    deque <Player*> players;
    vector<IObserver*>observers;
    Board* board;
    Rules* rules;
    IObserver* observer;
    bool gameOver;
public:
    Game(int bs){
        this->boardSize = bs;
        board = new Board(boardSize);
        rules = new standardRules();
        gameOver = false;
    }

    void addPlayer(Player* player){
        players.push_back(player);
    }

    void addObserver(IObserver* observer){
        observers.push_back(observer);
    }
    
    void notify(string msg){
        for(auto observer: observers){
            observer->updateMsg(msg);
        }
    }

    void play() {
        if(players.size() < 2){
            cout<<"Need atleast 2 players to start the game"<<endl;
            return;
        }

        notify("🤡🤡🤡🤡 Tic Tac Toe Game Started! 🤡🤡🤡🤡 :)");

        while(!gameOver){
            board->display();

            // Take out the current player from dequeue
            Player* currPlayer = players.front();
            cout<<currPlayer->getName()<<" "<<currPlayer->getSymbol()->getMark()<<" - Enter row and columns: "<<endl;

            int row, col;
            cin>>row>>col;

            // Check if move is valid or not
            if(rules->isValidMove(board, row, col)){
                board->placeMark(row, col, currPlayer->getSymbol());
                
                if(rules->checkWin(board, currPlayer->getSymbol())){
                    board->display();
                    notify(currPlayer->getName() +" wins the match🥳🥳");
                    currPlayer->incrementScore();

                    gameOver = true;
                }
                else if(rules->checkDraw(board)){
                    board->display();
                    notify("Is it a draw!");
                    gameOver = true;
                }
                else{
                    players.pop_front();
                    players.push_back(currPlayer);
                }
            }
            else{
                cout<<"Invalid move! Try Again"<<endl;
            }
        }
    }

    ~Game(){
        delete board;
        delete rules;
    }
};

#endif