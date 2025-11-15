//
// Created by yeskonerism on 15/11/2025.
//

#ifndef BUCKSHOT_ROULETTE_DEALER_H
#define BUCKSHOT_ROULETTE_DEALER_H

typedef struct {
    int health;
    int alive;
} Dealer;

void initDealer(Dealer* d, int health);
void damageDealer(Dealer* d, int amount);

void printDealer(Dealer d);

#endif //BUCKSHOT_ROULETTE_DEALER_H