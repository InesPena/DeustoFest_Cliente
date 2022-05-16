#ifndef SOCKETS_SOCKETS_H
#define SOCKETS_SOCKETS_H

#include <winsock2.h>

void establecerConexion(SOCKET comm_socket, char sendBuff[], char recvBuff[]);
void protocoloCliente(SOCKET comm_socket, char sendBuff[], char recvBuff[]);

#endif
