#ifndef DRAGON_H // Предотвращение многократного включения заголовочного файла
#define DRAGON_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Объявление структуры Dragon
typedef struct {
    char color[20];  // Цвет дракона
    int health;  // Здоровье дракона 
    int attack_min; // Минимальный урон, который дракон может нанести
    int attack_max; // Максимальный урон, который дракон может нанести
    int defense; // Защита дракона
} Dragon;

// Прототип функции для инициализации параметров двух драконов (красного и синего)
void init_dragons(Dragon* red, Dragon* blue);

// Прототип функции для атаки одного дракона на другого
void dragon_attack(Dragon* attacker, Dragon* defender);

// Прототип функции для вывода на экран текущего состояния драконов (здоровье, цвет)
void print_status(Dragon red, Dragon blue);

// Прототип функции для проверки, есть ли победитель в битве
int check_winner(Dragon red, Dragon blue);

#endif
