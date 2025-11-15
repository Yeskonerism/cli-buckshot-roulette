//
// Created by yeskonerism on 15/11/2025.
//

#ifndef BUCKSHOT_ROULETTE_SHOTGUN_H
#define BUCKSHOT_ROULETTE_SHOTGUN_H

#include <stdio.h>
#include <time.h>

typedef struct {
    int chambers[6];
    int currentChamber;
} Shotgun;

void nextChamber(Shotgun* s) {
    if(s->currentChamber < 6) {
        s->currentChamber++;
    }
    else printf("Shotgun complete\n");
}

void randomiseChambers(Shotgun* s) {
    //int maxChamber = rand() % 6 + 2;
    //s->chambers = int[maxChamber];

    srand(time(NULL));

    for(int i = 0; i < 6; i++) {
        s->chambers[i] = rand() % 2;
    }
}

void newShotgun(Shotgun* s) {
    randomiseChambers(s);
    s->currentChamber = 0;
}

void printChambers (Shotgun s) {
    for (int i = 0; i < 6; i++) {
        printf("Chamber %d: %d\n", i, s.chambers[i]);
    }
}

#endif //BUCKSHOT_ROULETTE_SHOTGUN_H