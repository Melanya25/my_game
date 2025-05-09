#ifndef DRAGON_H
#define DRAGON_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char color[20];
    int health;
    int attack_min;
    int attack_max;
    int defense;
} Dragon;

void init_dragons(Dragon* red, Dragon* blue);
void dragon_attack(Dragon* attacker, Dragon* defender);
void print_status(Dragon red, Dragon blue);
int check_winner(Dragon red, Dragon blue);

#endif
