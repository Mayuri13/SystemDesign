#include "./GameFactory.h"
#include "./utilities/Players.h"
#include "./utilities/GameType.h"
#include "./interfaces/IObserver.h"
#include "./consoleNotifier.h"
#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"==================== Tic Tac Toe Game Start =================="<<endl;

    int boardsize;
    cout<<"Enter board size: ";
    cin>>boardsize;

    Game* game = GameFactory::createGame(Gametype::STANDARD, boardsize);

    // Add Observer
    IObserver* notifier = new consoleNotifier();
    game->addObserver(notifier);
    
    Player* player1 = new Player(1, "Mayuri", new Symbol('X'));
    Player* player2 = new Player(2, "Souvik", new Symbol('O'));

    game->addPlayer(player1);
    game->addPlayer(player2);

    game->play();

    // cleanup
    delete game;
    delete player1;
    delete player2;
    delete notifier;

    return 0;
}