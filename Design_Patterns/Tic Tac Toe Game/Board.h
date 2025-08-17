#ifndef BOARD_H
#define BOARD_H
#include "./utilities/Symbols.h"
#include <bits/stdc++.h>
using namespace std;

class Board {
    vector<vector<Symbol*>>board;
    int boardSize;
    Symbol* emptyCell;
public:
    Board(int boardSize){
        this->boardSize = boardSize;
        emptyCell = new Symbol('-');
        board = vector<vector<Symbol*>>(boardSize, vector<Symbol*>(boardSize, emptyCell));
    }
    void display(){
        for(int i=0; i<boardSize; i++){
            for(int j=0; j<boardSize; j++){
                cout<<board[i][j]->getMark()<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    int getSize(){
        return boardSize;
    }

    void placeMark(int row, int col, Symbol* symbol){
        board[row][col] = symbol;
    }

    Symbol* getCell(int row, int col){
        return board[row][col];
    }

    Symbol* getEmptyCell(){
        return emptyCell;
    }

    bool isCellEmpty(int row, int col){
        if(row < 0 || row >= boardSize || col < 0 || col >= boardSize)
            return false;
        return board[row][col]->getMark() == '-';
    }

    ~Board() {
        delete emptyCell;
    }
};

#endif