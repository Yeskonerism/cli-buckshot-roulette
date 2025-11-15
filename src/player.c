//
// Created by yeskonerism on 15/11/2025.
//

#include "include/player.h"

void initPlayer(Player* p, string name, int health) {
    p->name = name;
    p->health = health;
    p->alive = 1;
}

void damagePlayer(Player* p, int damage) {
    p->health -= damage;
}

void printPlayer(Player p) {
    printf("Player: %s, Health: %d\n", p.name, p.health);
}