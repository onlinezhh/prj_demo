/*
 * Copyright (C) 2013 zhh
 */

#ifndef CORE_SIMP_SOCKET_H
#define CORE_SIMP_SOCKET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>

namespace SIMP_HTTP
{

class SIMP_Socket
{
public:
	SIMP_Socket() { m_socket = -1; }
	SIMP_Socket(int fd) : m_socket(fd) {}
	~SIMP_Socket() {}

public:
	int Listen(unsigned short port);
	SIMP_Socket* Accept();

	int Connect(const struct sockaddr* addr);

private:
	int m_socket;
};

}


#endif // CORE_SIMP_SOCKET_H
