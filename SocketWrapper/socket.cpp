#include "socket.h"

#include <stdexcept>
#include <string>
#include <arpa/inet.h>
#include <cerrno>
#include <iostream>
#include <cstring>

void handleSocketError(const std::string& errorMessage) {
    	std::cerr << errorMessage << ": ";
    	perror("");
}

Socket::Socket(Domain domain, Type type, int protocol) 
	: domain{domain}, type{type}, protocol{protocol}, socketFd{-1} 
{
}

Socket::~Socket() {
	close();
}

Socket Socket::socket() {
	return Socket(domain, type, protocol);
}

void Socket::create() {
	socketFd = ::socket(static_cast<int>(domain), static_cast<int>(type), protocol);
	if (socketFd == -1) {
	    handleSocketError("Failed to create socket");
	    throw std::runtime_error("Failed to create socket");
	}
	int reuse = 1;
    	if (setsockopt(socketFd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
        	throw std::runtime_error("Failed to set socket options");
    	}
}

void Socket::connect(const std::string& ipAddress, uint16_t port) {
    	sockaddr_in serverAddress{};
    	serverAddress.sin_family = static_cast<int>(domain);
    	serverAddress.sin_port = htons(port);
    	if (inet_pton(static_cast<int>(domain), ipAddress.c_str(), &(serverAddress.sin_addr)) <= 0) {
        	throw std::runtime_error("Invalid IP address");
    	}
    	if (::connect(socketFd, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
        	throw std::runtime_error("Failed to connect to server");
    	}
}

void Socket::bind(const std::string& ipAddress, uint16_t port) {
	sockaddr_in address{};
    	address.sin_family = static_cast<int>(domain);
    	address.sin_port = htons(port);
    	if (inet_pton(static_cast<int>(domain), ipAddress.c_str(), &(address.sin_addr)) <= 0) {
    		handleSocketError("Invalid IP address");
        	throw std::runtime_error("Invalid IP address");
    	}
    	if (::bind(socketFd, reinterpret_cast<sockaddr*>(&address), sizeof(address)) == -1) {
    		handleSocketError("Failed to bind socket");
        	throw std::runtime_error("Failed to bind socket");
    	}
}

void Socket::listen(int backlog) {
	if (::listen(socketFd, backlog) == -1) {
        	throw std::runtime_error("Failed to listen on socket");
    	}
}

Socket Socket::accept() {
	sockaddr_in clientAddress{};
    	socklen_t clientAddressLength = sizeof(clientAddress);
    	int newSocketFd = ::accept(socketFd, reinterpret_cast<sockaddr*>(&clientAddress), &clientAddressLength);
    	if (newSocketFd == -1) {
        	throw std::runtime_error("Failed to accept connection");
    	}
    	Socket newSocket(domain, type, protocol);
    	newSocket.socketFd = newSocketFd;
    	newSocket.localIpAddress = inet_ntoa(clientAddress.sin_addr);
    	newSocket.localPort = ntohs(clientAddress.sin_port);
    	newSocket.remoteIpAddress = inet_ntoa(clientAddress.sin_addr);
    	newSocket.remotePort = ntohs(clientAddress.sin_port);
    	return newSocket;
}

ssize_t Socket::send(const void* data, size_t size) {
    	ssize_t sentBytes = ::send(socketFd, data, size, 0);
    	if (sentBytes == -1) {
        	throw std::runtime_error("Failed to send data: " + std::string(strerror(errno)));
    	} 
	else if (static_cast<size_t>(sentBytes) != size) {
        	throw std::runtime_error("Failed to send complete data");
    	}
    	return sentBytes;
}

ssize_t Socket::recv(void* buffer, size_t size) {
	ssize_t receivedBytes = ::recv(socketFd, buffer, size, 0);
    	if (receivedBytes == -1) {
        	throw std::runtime_error("Failed to receive data");
    	}
    	return receivedBytes;
}

void Socket::close() {
	if (socketFd != -1) {
		::close(socketFd);
		socketFd = -1;
	}
}

int Socket::getSocketFd() const {
	return socketFd;
}

Domain Socket::getDomain() const {
	return domain;
}

Type Socket::getType() const {
	return type;
}

int Socket::getProtocol() const {
	return protocol;
}

std::string Socket::getLocalIpAddress() const {
	return localIpAddress;
}

uint16_t Socket::getLocalPort() const {
	return localPort;
}

std::string Socket::getRemoteIpAddress() const {
	return remoteIpAddress;
}

uint16_t Socket::getRemotePort() const {
	return remotePort;
}
