#ifndef STANDARD_RULES_H
#define STANDARD_RULES_H
#include "./interfaces/Rules.h"
#include "./Board.h"

class standardRules : public Rules {
public:
    bool isValidMove(Board* board, int row, int col) {
        return board->isCellEmpty(row, col);
    }
    bool checkWin(Board* board, Symbol* symbol) {
        int size = board->getSize();
        
        // Check rows
        for(int i = 0; i < size; i++) {
            bool win = true;
            for(int j = 0; j < size; j++) {
                if(board->getCell(i, j) != symbol) {
                    win = false;
                    break;
                }
            }
            if(win) return true;
        }
        
        // Check columns
        for(int j = 0; j < size; j++) {
            bool win = true;
            for(int i = 0; i < size; i++) {
                if(board->getCell(i, j) != symbol) {
                    win = false;
                    break;
                }
            }
            if(win) return true;
        }
        
        // Check main diagonal
        bool win = true;
        for(int i = 0; i < size; i++) {
            if(board->getCell(i, i) != symbol) {
                win = false;
                break;
            }
        }
        if(win) return true;
        
        // Check anti-diagonal
        win = true;
        for(int i = 0; i < size; i++) {
            if(board->getCell(i, size-1-i) != symbol) {
                win = false;
                break;
            }
        }
        return win;
    }
    
    bool checkDraw(Board* board) {
        int size = board->getSize();
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(board->getCell(i, j) == board->getEmptyCell()) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif