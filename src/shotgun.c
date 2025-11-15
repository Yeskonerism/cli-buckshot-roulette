//
// Created by yeskonerism on 15/11/2025.
//

#include "include/shotgun.h"
#include "include/game.h"

void randomiseChambers(Shotgun* s) {
    srand(time(NULL));

    for(int i = 0; i < 6; i++) {
        s->chambers[i] = rand() % 2;
    }
}

void newShotgun(Shotgun* s) {
    randomiseChambers(s);

    s->currentChamber = 0;
    s->game->turn = PLAYER;
}

void nextChamber(Shotgun* s) {
    if(s->currentChamber < 5) {
        s->currentChamber++;
    }
    else {
        printf("Shotgun complete\n");
        newShotgun(s);

        printChambers(*s);
    }
}

void printChambers (Shotgun s) {
    int chambersOrganised[6];
    int chambersOrganisedIndex = 0;

    int blankCount = 0, bulletCount = 0;

    for (int i = 0; i < 6; i++) {
        if (s.chambers[i] == 1) {
            chambersOrganised[chambersOrganisedIndex] = s.chambers[i];
            chambersOrganisedIndex++;
        }
    }

    for (int i = 0; i < 6; i++) {
        if (chambersOrganised[i] == 1) {
            bulletCount++;
        } else {
            blankCount++;
        }
    }
    printf("%d Live | %d Blank\n", bulletCount, blankCount);
}

int numberLives(Shotgun s) {
    int liveCount = 0;

    for (int i = 0; i < 6; i++) {
        if (s.chambers[i] == 1) {
            liveCount++;
        }
    }

    return liveCount;
}