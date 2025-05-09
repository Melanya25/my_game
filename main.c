#include "dragon.h"

int main() {
    srand(time(0)); // Инициализация генератора случайных чисел
    
    Dragon red, blue;
    init_dragons(&red, &blue);
    
    printf("Dragon Battle Begins!\n");
    printf("Red Dragon vs Blue Dragon\n\n");
    
    int round = 1;
    while (1) {
        printf("=== Round %d ===\n", round++);
        
        // Красный дракон атакует первым
        dragon_attack(&red, &blue);
        if (check_winner(red, blue)) break;
        print_status(red, blue);
        
        // Синий дракон атакует в ответ
        dragon_attack(&blue, &red);
        if (check_winner(red, blue)) break;
        print_status(red, blue);
        
        // Пауза между раундами
        printf("Press Enter to continue...");
        getchar();
    }
    
    return 0;
}
