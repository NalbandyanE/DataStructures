#include "socket.h"

#include <iostream>
#include <cstring> 

int main() {
    try {
        Socket clientSocket(Domain::DOMAIN_AF_INET, Type::TYPE_SOCK_STREAM, 0);
        clientSocket.create();
        clientSocket.connect("192.168.1.8", 8080);
        std::cout << "Connected to server at 192.168.1.8:8080" << std::endl;
        std::string userInput;
        std::cout << "Enter some text: ";
        std::getline(std::cin, userInput);
        ssize_t sentBytes = clientSocket.send(userInput.c_str(), userInput.size());
        if (sentBytes == -1) {
            throw std::runtime_error("Failed to send data: " + std::string(strerror(errno)));
        }
        if (sentBytes != static_cast<ssize_t>(userInput.size())) {
            throw std::runtime_error("Failed to send complete data");
        }
        char buffer[1024];
        ssize_t receivedBytes = clientSocket.recv(buffer, sizeof(buffer));
        std::string convertedText(buffer, receivedBytes);
        std::cout << "Converted text: " << convertedText << std::endl;
        clientSocket.close();
    } catch (const std::exception& ex) {
        std::cerr << "Exception occurred: " << ex.what() << std::endl;
    }

    return 0;
}
