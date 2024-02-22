#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket == -1) {
        std::cerr << "Error creating socket." << std::endl;
        return -1;
    }

    sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(12345);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        std::cerr << "Error connecting to server." << std::endl;
        close(client_socket);
        return -1;
    }

    std::cout << "Enter messages to send to the server. Type 'exit' to close the connection." << std::endl;
    char message[1024];

    while (true) {
        std::cin.getline(message, sizeof(message));
        send(client_socket, message, strlen(message), 0);

        if (strcmp(message, "exit") == 0) {
            std::cout << "Exiting..." << std::endl;
            break;
        }
    }

    close(client_socket);
    return 0;
}
