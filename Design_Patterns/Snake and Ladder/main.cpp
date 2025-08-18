#include <bits/stdc++.h>
#include "./GameFactory.h"
#include "./Player.h"
#include "./Game.h"
#include "./utilities/GameType.h"

using namespace std;

int main(){
    Game* game = GameFactory::createGame(GameType::STANDARD);

    Player* player1 = new Player(1, "Mayuri");
    Player* player2 = new Player(2, "Souvik");

    game->addPlayer(player1);
    game->addPlayer(player2);

    cout<<"=================== Snake and Ladder ==================="<<endl;

    game->play();

    return 0;
}