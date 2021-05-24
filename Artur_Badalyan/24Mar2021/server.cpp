#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define ERROR_S "SERVER_ERROR"
#define DEFAULT_PORT 1602
#define BUFFER_SIZE 1024
#define CLIENT_CLOSE_CONNECTION_SYMBOL '#'

int main(int argc, char const* argv[]){
	int client;
	int server;

	struct sockaddr_in s_address;
	bool is_client_connection_close(const char* msg);

	client = socket(AF_INET, SOCK_STREAM, 0);

	if(client < 0) {
		std::cout << "SERVER ERROR: socket error."<<std::endl;
		exit(0);
	}

	std::cout << "SERVER: Socket for server created."<<std::endl;

	s_address.sin_port = htons(DEFAULT_PORT);
	s_address.sin_family = AF_INET;
	s_address.sin_addr.s_addr = htons(INADDR_ANY);

	int ret = bind(client, reinterpret_cast<struct sockaddr*>(&s_address),sizeof(s_address));				

	if (ret < 0){
		std::cout<< "SERVER ERROR: Socket has already been establishing.\n";
		return -1;
	}

	socklen_t size = sizeof(s_address);
	std::cout << "SERVER: " << "Listening clients...\n";
	listen(client,1);

	server = accept(client, reinterpret_cast<struct sockaddr*>(&s_address),&size);
	if (server < 0){
		std::cout << "SERVER ERROR: Can't accepting client.\n";
	}
	
	char buffer[BUFFER_SIZE];
	bool isExit = false;
	while (server > 0){
		strcpy(buffer,"=> Server conected!\n");
		send(server,buffer,BUFFER_SIZE,0);
		std::cout << "=> Conected to the client #1" <<std::endl
			<< "Enter " <<  CLIENT_CLOSE_CONNECTION_SYMBOL << " to end the connection\n\n";

		std::cout << "Client: ";
		recv(server,buffer,BUFFER_SIZE,0);
		std::cout << buffer << std::endl;
		if (is_client_connection_close(buffer)) {
			isExit = true;
		}
		
		while (!isExit) {
			std::cout << "Server: ";
			std::cin.getline(buffer, BUFFER_SIZE);
			send(server, buffer, BUFFER_SIZE, 0);
			if (is_client_connection_close(buffer)){
				break;
			}
			std::cout << "Client: ";
			recv (server, buffer, BUFFER_SIZE, 0);
			std::cout << buffer <<std::endl;
			if (is_client_connection_close(buffer)){
				break;	
			}
		}
		
		std::cout << "\n GoodBye..."<<std::endl;
		isExit = false;
		exit(1);	
	}
		return 0;	
}

bool is_client_connection_close(const char* msg) {
	for(int i = 0;i < strlen(msg);++i){
		if (msg[i] ==  CLIENT_CLOSE_CONNECTION_SYMBOL){
			return true;
		}
	}

	return false;
}	

