#ifndef RULES
#define RULES
// #include "../Board.h"
// #include "../Player.h"

class Board;   // forward declaration
class Player;

class Rules{
public:
    virtual int roleDice() = 0;
    virtual bool checkWin(int score) = 0;
    virtual bool checkSnake(Board* board, Player* player, int score) = 0;
    virtual bool checkLadder(Board* board, Player* player, int score) = 0;
    virtual bool isValidScore(Board* board, Player* player, int score) = 0;
};

#endif