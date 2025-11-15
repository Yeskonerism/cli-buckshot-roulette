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

void initPlayer(Player* p, string name, int health);
void damagePlayer(Player *p, int amount);

void printPlayer(Player p);

#endif //BUCKSHOT_ROULETTE_PLAYER_H