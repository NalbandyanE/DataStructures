#include "socket.h"

#include <iostream>
#include <cstring> 

int main() {
    try {
        UDPSocket udpClientSocket(Domain::DOMAIN_AF_INET, 0);
        udpClientSocket.create();
        sockaddr_in destAddress{};
        destAddress.sin_family = static_cast<int>(udpClientSocket.getDomain());
        destAddress.sin_port = htons(8080);
        std::cout << "Connected to server" << std::endl;
        std::string userInput;
        std::cout << "Enter some text: ";
        std::getline(std::cin, userInput);
        ssize_t sentBytes = udpClientSocket.sendto(userInput.c_str(), userInput.size(), &destAddress, sizeof(destAddress));
        if (sentBytes == -1) {
            throw std::runtime_error("Failed to send data: " + std::string(strerror(errno)));
        }
        if (sentBytes != static_cast<ssize_t>(userInput.size())) {
            throw std::runtime_error("Failed to send complete data");
        }
        char buffer[1024];
        sockaddr_in serverAddress;
        socklen_t serverAddressLength = sizeof(serverAddress);
        ssize_t receivedBytes = udpClientSocket.recvfrom(buffer, sizeof(buffer), &serverAddress, &serverAddressLength);
        std::string convertedText(buffer, receivedBytes);
        std::cout << "Converted text: " << convertedText << std::endl;
        udpClientSocket.close();
    } catch (const std::exception& ex) {
        std::cerr << "Exception occurred: " << ex.what() << std::endl;
    }

    return 0;
}