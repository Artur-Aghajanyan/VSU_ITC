#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define DEFAULT_PORT 8001
#define BUFFER_SIZE 1024
#define CLIENT_CLOSE_CONNECTION_SYMBOL '#'

bool is_client_connection_close(const char* msg);

int main(int argc, char const* argv[]) {
	int server, client;
	struct sockaddr_in serverAddress;

	client = socket(AF_INET, SOCK_STREAM , 0);
	if(client < 0) {
		std::cout << "Server ERROR\n";
		return -1;
	}

	std::cout << "Socket for server was successfully created\n";

	serverAddress.sin_port = htons(DEFAULT_PORT);
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htons(INADDR_ANY);

	int ret = bind(client, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
	if(ret < 0) {
		std::cout << "SERVER ERROR";
		return -1;
	}

	socklen_t size = sizeof(serverAddress);
	std::cout << "SERVER: Listaning clients\n";

	listen(client, 6);

	server = accept(client, (struct sockaddr*)&serverAddress, &size);
	if(server < 0) {
		std::cout << "ERROR TYR ACCEPT";
		return -1;
	}
	
	char buffer[BUFFER_SIZE];
	bool isExit = false;
	while (server > 0) {
		strcpy(buffer, " -> SERRVER CONNECTED\n");
		send(server, buffer, BUFFER_SIZE, 0);
		std::cout << "Conected to the client #1" <<std::endl 
		<< "Enter " <<  CLIENT_CLOSE_CONNECTION_SYMBOL << " to end the connection.\n\n";
		std::cout << "Client: ";
		recv(server,buffer,BUFFER_SIZE,0);
		std::cout << buffer << std::endl;
		if (is_client_connection_close(buffer))
			isExit = true;
		
		while (!isExit) {
			std::cout << "Server: ";
			std::cin.getline(buffer, BUFFER_SIZE);
			send(server, buffer, BUFFER_SIZE, 0);
			if (is_client_connection_close(buffer))
				break;

			std::cout << "Client: ";
			recv (server, buffer, BUFFER_SIZE, 0);
			std::cout << buffer <<std::endl;
			if (is_client_connection_close(buffer))
				break;
		}
		
		std::cout << "\nGoodBye..."<<std::endl;
		isExit = false;
		exit(1);	
	}
	return 0;
}

bool is_client_connection_close(const char* msg) {
	for(int i = 0; i < strlen(msg); ++i){
		if (msg[i] ==  CLIENT_CLOSE_CONNECTION_SYMBOL){
			return true;
		}
	}
	return 0;
}