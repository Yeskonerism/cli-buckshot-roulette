//
// Created by yeskonerism on 15/11/2025.
//

#ifndef BUCKSHOT_ROULETTE_SHOTGUN_H
#define BUCKSHOT_ROULETTE_SHOTGUN_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct Game Game;

typedef struct {
    int chambers[6];
    int currentChamber;

    Game *game;
} Shotgun;

void randomiseChambers(Shotgun* s);

void newShotgun(Shotgun* s);

void nextChamber(Shotgun* s);

void printChambers (Shotgun s);

int numberLives(Shotgun s);

#endif //BUCKSHOT_ROULETTE_SHOTGUN_H