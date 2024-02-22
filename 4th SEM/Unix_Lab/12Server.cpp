#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        std::cerr << "Error creating socket." << std::endl;
        return -1;
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        std::cerr << "Error binding socket." << std::endl;
        close(server_socket);
        return -1;
    }

    listen(server_socket, 5);
    std::cout << "Server is listening for connections..." << std::endl;

    int client_socket = accept(server_socket, nullptr, nullptr);
    if (client_socket == -1) {
        std::cerr << "Error accepting connection." << std::endl;
        close(server_socket);
        return -1;
    }

    std::cout << "Client connected successfully..." << std::endl;
    char buffer[1024] = {0};

    while (true) {
        recv(client_socket, buffer, sizeof(buffer), 0);
        std::cout << "Received from client: " << buffer << std::endl;

        if (strcmp(buffer, "exit") == 0) {
            std::cout << "Client has exited. Closing connection." << std::endl;
            break;
        }

        memset(buffer, 0, sizeof(buffer));
    }

    close(client_socket);
    close(server_socket);
    return 0;
}

