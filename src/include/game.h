//
// Created by yeskonerism on 15/11/2025.
//

#ifndef BUCKSHOT_ROULETTE_GAME_H
#define BUCKSHOT_ROULETTE_GAME_H

#include "player.h"
#include "shotgun.h"

typedef struct {
    Shotgun shotgun;
    Player player;
    int gameLoop;
} Game;

void endGame(Game* g) {
    g->gameLoop = 0;
}

void gameLoop(Game* g) {
    while(g->gameLoop) {
        printPlayer(g->player);
        printChambers(g->shotgun);

        endGame(g);
    }
}

void newGame(Game* g) {
    g->gameLoop = 1;

    newShotgun(&g->shotgun);

    string playerName = getPlayerName();
    initPlayer(&g->player, playerName, 5);

    gameLoop(g);
}

#endif //BUCKSHOT_ROULETTE_GAME_H