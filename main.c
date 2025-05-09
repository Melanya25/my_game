#include "dragon.h"  // Включение заголовочного файла dragon.h

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел на основе текущего времени.

    Dragon red, blue; // Объявление двух структур Dragon: red (красный дракон) и blue (синий дракон)
    init_dragons(&red, &blue); 

    printf("Dragon Battle Begins!\n"); 
    printf("Red Dragon vs Blue Dragon\n\n"); 

    int round = 1; // Инициализация переменной round (номер раунда) значением 1
    int winner = 0; // Флаг победителя: 0 - нет победителя, 1 - битва завершена

    // Основной цикл битвы
    while (!winner) { // Цикл продолжается до тех пор, пока winner равен 0 
        printf("=== Round %d ===\n", round++); 

        // Красный дракон атакует первым
        dragon_attack(&red, &blue); 
        winner = check_winner(red, blue); // Проверка, есть ли победитель после атаки красного дракона.
                                             
        print_status(red, blue); // Вывод текущего состояния драконов (здоровье)

        // Синий дракон атакует в ответ (если нет победителя)
        if (!winner) { // Проверяем, что победителя еще нет
            dragon_attack(&blue, &red);
            winner = check_winner(red, blue); // Проверка, есть ли победитель после атаки синего дракона.
            print_status(red, blue); // Вывод текущего состояния драконов (здоровье)
        }


        // Пауза между раундами
        printf("Press Enter to continue..."); 
        getchar(); // Ожидание нажатия клавиши Enter.
    }

    return 0; // Завершение программы
}
