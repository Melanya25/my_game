##Описание проекта
# Dragon Battle Game

![Dragon Battle](https://img.icons8.com/color/96/000000/dragon.png)

Консольная игра "Битва драконов" на языке C, где сражаются два дракона с разными характеристиками.

## Особенности
- Пошаговая битва между красным и синим драконами
- Случайный расчет урона с учетом защиты
- Простая текстовая графика
- Кроссплатформенная сборка через Makefile

## Требования
- Компилятор GCC
- Make (для сборки)
- Linux/macOS/WSL (для Windows)

## Установка и запуск
```bash
# Клонировать репозиторий
git clone https://github.com/Melanya25/my_game.git
cd my_game

# Сборка проекта
make

# Запуск игры
./dragon_battle

##Управление
Нажимайте Enter для перехода к следующему раунду
Игра автоматически завершится при победе одного из драконов

Структура проекта
my_game/
├── src/               # Исходные файлы
│   ├── main.c         # Основная логика
│   ├── dragon.c       # Функции драконов
│   └── dragon.h       # Заголовочный файл
├── Makefile           # Файл сборки
├── README.md          # Этот файл
└── .gitignore         # Игнорируемые файлы

##Лицензия
MIT License

https://img.shields.io/badge/License-MIT-yellow.svg

### Файл `.gitignore`

##Объектные файлы
*.o

##Исполняемые файлы
dragon_battle
*.exe
*.out

##Резервные копии
*~
*.bak

##Файлы IDE
.vscode/
.idea/

##Системные файлы
.DS_Store
Thumbs.db

##Логи
*.log

##Временные файлы
*.swp
*.swo

##Автоматически генерируемые файлы
a.out
