#ifndef RULES_H
#define RULES_H
#include "../Board.h"

// Strategy Design Pattern -> by adding behavioural concrete classes like, Standard Rules
class Rules{
public:
    virtual bool isValidMove(Board* board, int row, int col) = 0;
    virtual bool checkWin(Board* board, Symbol* symbol) = 0;
    virtual bool checkDraw(Board* board) = 0;
};

#endif