#include "server.h"

int main()
{
	Server server;

	if(!server.start(8000)) return -1;

	server.acceptClient();

}
// g++ server_main.cpp server.cpp -lws2_32 -o exe