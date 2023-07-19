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
        Socket serverSocket(Domain::DOMAIN_AF_INET, Type::TYPE_SOCK_STREAM, 0);
        serverSocket.create();
        serverSocket.bind("192.168.1.8", 8080);
        serverSocket.listen(5);
        std::cout << "Server listening on 192.168.1.8:8080" << std::endl;
        Socket clientSocket = serverSocket.accept();
        std::cout << "Accepted incoming connection from client" << std::endl;
        char buffer[1024];
        ssize_t receivedBytes = clientSocket.recv(buffer, sizeof(buffer));
        std::string receivedText(buffer, receivedBytes);
        std::string uppercaseText = toUpper(receivedText);
        clientSocket.send(uppercaseText.c_str(), uppercaseText.size());
        clientSocket.close();
        serverSocket.close();
    } catch (const std::exception& ex) {
        std::cerr << "Exception occurred: " << ex.what() << std::endl;
    }

    return 0;
}
