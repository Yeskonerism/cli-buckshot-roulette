//
// Created by yeskonerism on 15/11/2025.
//

#include "include/game.h"

void newGame(Game* g) {
    g->gameLoop = 1;

    initDealer(&g->dealer, 5);

    g->shotgun.game = g;
    newShotgun(&g->shotgun);

    string playerName = str_input("Enter player name");

    while (str_equals(playerName, "god") || str_equals(playerName, "dealer")) {
        if (str_equals(playerName, "god")) {
            printf("god is dead...\n");
        } else if (str_equals(playerName, "dealer")) {
            printf("There can only be one...\n");
        }
        playerName = str_input("Enter player name");
    }

    initPlayer(&g->player, playerName, 5);

    g->turn = PLAYER;

    gameLoop(g);
}

//
// Main game loop
//
void gameLoop(Game* g) {
    printChambers(g->shotgun);

    while(g->gameLoop) {
        switch (g->turn) {
            case PLAYER:
                playerTurn(g);
                break;
            case DEALER:
                dealerTurn(g);
                break;
        }

        checkEndCase(g);
        nextChamber(&g->shotgun);
    }
}

void endGame(Game* g) {
    g->gameLoop = 0;
}

void playerTurn(Game* g) {
    const string input = str_buff(str_input_buff("Shoot self or dealer? [s/d]: ", 8), 8);

    if (str_equals(input, "s")) {
        if (g->shotgun.chambers[g->shotgun.currentChamber] == 1) {
            printf("BOOM!\n");
            damagePlayer(&g->player, 1);

            printPlayer(g->player);

            // switch turns
            switchTurn(g);
        } else {
            printf("click...\n");
        }
    } else if (str_equals(input, "d")) {
        if (g->shotgun.chambers[g->shotgun.currentChamber] == 1) {
            damageDealer(&g->dealer, 1);
            printDealer(g->dealer);
        } else {
            printf("click...\n");
        }

        switchTurn(g);
    } else {
        printf("Invalid input\n");
    }
}

void dealerTurn(Game* g) {
    int shootSelf = rand() % 2;

    if (shootSelf == 0) {
        printf("Dealer shoots you\n");

        if (g->shotgun.chambers[g->shotgun.currentChamber] == 1) {
            printf("BOOM!\n");

            damagePlayer(&g->player, 1);
            printPlayer(g->player);
        } else {
            printf("click...\n");
        }

        // switch turns
        switchTurn(g);
    } else {
        printf("Dealer shoots himself!\n");

        if (g->shotgun.chambers[g->shotgun.currentChamber] == 1) {
            printf("BOOM!\n");

            damageDealer(&g->dealer, 1);
            printDealer(g->dealer);

            switchTurn(g);
        } else {
            printf("click...\n");
        }
    }
}

void switchTurn(Game* g) {
    if(g->turn == PLAYER) {
        g->turn = DEALER;
    } else {
        g->turn = PLAYER;
    }
}

void checkEndCase(Game* g) {
    if (g->player.health <= 0) {
        printf("You are dead!\n");
        endGame(g);
    } else if (g->dealer.health <= 0) {
        printf("Dealer is dead!\n");
        endGame(g);
    }
}