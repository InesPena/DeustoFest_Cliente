#ifndef SOCKETS_SOCKETS_H
#define SOCKETS_SOCKETS_H

#include <winsock2.h>

namespace gestores
{
	class GestorSocket
	{
	private:
		SOCKET s;
		char sendBuff[512];
		char recvBuff[512];

	public:
		GestorSocket();
		~GestorSocket();
		void establecerConexion(SOCKET comm_socket, char sendBuff[], char recvBuff[]);
		void protocoloCliente(SOCKET comm_socket, char sendBuff[], char recvBuff[]);
	};
}





#endif
