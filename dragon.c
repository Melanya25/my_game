#include "dragon.h"

void init_dragons(Dragon* red, Dragon* blue) {
    // Инициализация красного дракона
    strcpy(red->color, "Red");
    red->health = 100;
    red->attack_min = 10;
    red->attack_max = 20;
    red->defense = 5;
    
    // Инициализация синего дракона
    strcpy(blue->color, "Blue");
    blue->health = 100;
    blue->attack_min = 8;
    blue->attack_max = 25;
    blue->defense = 7;
}

void dragon_attack(Dragon* attacker, Dragon* defender) {
    int damage = (rand() % (attacker->attack_max - attacker->attack_min + 1)) + attacker->attack_min;
    damage -= defender->defense;
    
    if (damage < 1) damage = 1;
    
    defender->health -= damage;
    
    printf("%s dragon attacks for %d damage!\n", attacker->color, damage);
}

void print_status(Dragon red, Dragon blue) {
    printf("\n--- Battle Status ---\n");
    printf("Red Dragon: %d HP\n", red.health);
    printf("Blue Dragon: %d HP\n", blue.health);
    printf("---------------------\n\n");
}

int check_winner(Dragon red, Dragon blue) {
    if (red.health <= 0 && blue.health <= 0) {
        printf("Both dragons have fallen! It's a draw!\n");
        return 1;
    } else if (red.health <= 0) {
        printf("Blue dragon wins the battle!\n");
        return 1;
    } else if (blue.health <= 0) {
        printf("Red dragon wins the battle!\n");
        return 1;
    }
    return 0;
}
