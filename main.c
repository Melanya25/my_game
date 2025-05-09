#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "dragon.h"

#define PORT 8080

void handle_client(int client_socket) {
    Dragon red, blue;
    init_dragons(&red, &blue);
    
    char buffer[1024] = {0};
    const char *welcome_msg = "Добро пожаловать в Битву Драконов!\n";
    send(client_socket, welcome_msg, strlen(welcome_msg), 0);
    
    while(1) {
        // Логика игры здесь
        char status[512];
        sprintf(status, "Red: %d HP | Blue: %d HP\n", red.health, blue.health);
        send(client_socket, status, strlen(status), 0);
        
        // ... остальная игровая логика
        
        if(check_winner(red, blue)) break;
        sleep(1);
    }
}

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Создаем сокет
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // Настраиваем сокет
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // Привязываем сокет к порту
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Слушаем соединения
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Сервер запущен на порту %d\n", PORT);
    
    while(1) {
        // Принимаем новое соединение
        if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        
        // Обрабатываем клиента
        handle_client(client_socket);
        close(client_socket);
    }
    
    return 0;
}
