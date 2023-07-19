#ifndef SOCKET_H
#define SOCKET_H

#include <string>

#ifdef _WIN32
    	#include <winsock2.h>
    	#pragma comment(lib, "ws2_32.lib")
#else
    	#include <sys/types.h>
    	#include <sys/socket.h>
    	#include <netinet/in.h>
    	#include <arpa/inet.h>
    	#include <unistd.h>
#endif

enum class Domain {
	DOMAIN_AF_INET = 2,
	DOMAIN_AF_INET6 = 10
};

enum class Type {
	TYPE_SOCK_STREAM = 1,
	TYPE_SOCK_DGRAM = 2
};

class Socket {
public:
	Socket(Domain, Type, int);
    	~Socket();
    	Socket socket();
    	void create();
	void connect(const std::string&, uint16_t);
    	void bind(const std::string&, uint16_t);
    	void listen(int);
    	Socket accept();
    	ssize_t send(const void*, size_t);
    	ssize_t recv(void*, size_t);
    	void close();
    	int getSocketFd() const;
    	Domain getDomain() const;
    	Type getType() const;
    	int getProtocol() const;
    	std::string getLocalIpAddress() const;
    	uint16_t getLocalPort() const;
    	std::string getRemoteIpAddress() const;
    	uint16_t getRemotePort() const;
private:
	Domain domain;
	Type type;
	int protocol;
	int socketFd;
	std::string localIpAddress;
    	uint16_t localPort;
    	std::string remoteIpAddress;
    	uint16_t remotePort;
};

#endif // SOCKET_H
