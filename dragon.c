#include "dragon.h"

// Функция для инициализации параметров двух драконов (красного и синего)
void init_dragons(Dragon* red, Dragon* blue) {
    // Инициализация красного дракона
    strcpy(red->color, "Red"); // Установка цвета красного дракона
    red->health = 100;
    red->attack_min = 10;
    red->attack_max = 20;
    red->defense = 5;  // Установка защиты красного дракона
    
    // Инициализация синего дракона
    strcpy(blue->color, "Blue"); // Установка цвета синего дракона
    blue->health = 100; // Установка начального здоровья синего дракона
    blue->attack_min = 8;
    blue->attack_max = 25;
    blue->defense = 7;  // Установка защиты красного дракона
}
// Функция для атаки одного дракона на другого
void dragon_attack(Dragon* attacker, Dragon* defender) {

    // Вычисление урона: случайное число в диапазоне от attack_min до attack_max
    int damage = (rand() % (attacker->attack_max - attacker->attack_min + 1)) + attacker->attack_min;
    // Уменьшение урона на величину защиты защищающегося дракона
    damage -= defender->defense;

     // Минимальный урон равен 1 
    if (damage < 1) damage = 1;

    // Уменьшение здоровья защищающегося дракона
    defender->health -= damage;
    
    printf("%s dragon attacks for %d damage!\n", attacker->color, damage);
}
// Функция для вывода на экран текущего состояния драконов (здоровье, цвет)
void print_status(Dragon red, Dragon blue) {
    printf("\n--- Battle Status ---\n");
    printf("Red Dragon: %d HP\n", red.health);
    printf("Blue Dragon: %d HP\n", blue.health);
    printf("---------------------\n\n");
}
// Функция для проверки, есть ли победитель в битве
int check_winner(Dragon red, Dragon blue) {
    // Проверка на ничью (оба дракона мертвы)
    if (red.health <= 0 && blue.health <= 0) {
        printf("Both dragons have fallen! It's a draw!\n");
        return 1;
        // Проверка, победил ли синий дракон
    } else if (red.health <= 0) {
        printf("Blue dragon wins the battle!\n");
        return 1;
        // Проверка, победил ли красный дракон
    } else if (blue.health <= 0) {
        printf("Red dragon wins the battle!\n");
        return 1;
    }
    // Победителя пока нет
    return 0;
}
