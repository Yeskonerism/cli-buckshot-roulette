//
// Created by yeskonerism on 15/11/2025.
//

#ifndef BUCKSHOT_ROULETTE_PLAYER_H
#define BUCKSHOT_ROULETTE_PLAYER_H

#include <stdio.h>

#include "string.h"

typedef struct {
    string name;
    int health;
    int alive;
} Player;

void initPlayer(Player* p, string name, int health) {
    p->name = name;
    p->health = health;
    p->alive = 1;
}

void damagePlayer(Player *p, int amount) {
    p->health -= amount;

    if(p->health <= 0) {
        p->health = 0;
        p->alive = 0;
    }
}

void printPlayer(Player p) {
    printf("%s - %dhp\n", p.name, p.health);
}

string getPlayerName() {
    string playerName = str_buff("",99); // create a buffer for the player name

    printf("Please enter your name: ");
    scanf("%99s", playerName); // limit scanf to 99 characters to prevent buffer overflow

    return playerName;
}

#endif //BUCKSHOT_ROULETTE_PLAYER_H