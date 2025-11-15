//
// Created by yeskonerism on 15/11/2025.
//

#include "include/dealer.h"

#include <stdio.h>

void initDealer(Dealer* d, int health) {
    d->health = health;
    d->alive = 1;
}

void damageDealer(Dealer* d, int amount) {
    d->health -= amount;

    if (d->health <= 0) {
        d->alive = 0;
    }
}

void printDealer(Dealer d) {
    printf("Dealer - Health: %d\n", d.health);
}