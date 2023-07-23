#include "socket.h"

#include <iostream>
#include <algorithm>
#include <cctype>

std::string toUpper(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { 
        return std::toupper(c); 
    });
    return result;
}

int main() {
    try {
        UDPSocket udpServerSocket(Domain::DOMAIN_AF_INET, 0);
        udpServerSocket.create();
        udpServerSocket.bind("192.168.1.8", 8080);
        std::cout << "UDP Server listening on 192.168.1.8:8080" << std::endl;
        while (true) {
            char udpBuffer[1024];
            sockaddr_in clientAddress;
            socklen_t clientAddressLength = sizeof(clientAddress);
            ssize_t receivedBytesUDP = udpServerSocket.recvfrom(udpBuffer, sizeof(udpBuffer), &clientAddress, &clientAddressLength);
            std::string receivedTextUDP(udpBuffer, receivedBytesUDP);
            std::string uppercaseTextUDP = toUpper(receivedTextUDP);
            udpServerSocket.sendto(uppercaseTextUDP.c_str(), uppercaseTextUDP.size(), &clientAddress, clientAddressLength);
        }
        udpServerSocket.close();
    } catch (const std::exception& ex) {
        std::cerr << "Exception occurred: " << ex.what() << std::endl;
    }

    return 0;
}