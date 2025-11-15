//
// Created by yeskonerism on 15/11/2025.
//

#ifndef BUCKSHOT_ROULETTE_GAME_H
#define BUCKSHOT_ROULETTE_GAME_H

#include "player.h"
#include "shotgun.h"
#include "dealer.h"

typedef enum {
    PLAYER,
    DEALER
}  GameTurn;

typedef struct Game {
    Shotgun shotgun;
    Player player;
    Dealer dealer;

    int gameLoop;

    GameTurn turn;
};

void newGame(Game* g);
void gameLoop(Game* g);
void endGame(Game* g);

void switchTurn(Game* g);

void playerTurn(Game* g);
void dealerTurn(Game* g);

void checkEndCase(Game *g);

#endif //BUCKSHOT_ROULETTE_GAME_H