#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define DEFAULT_PORT 8001
#define BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_CLOSE_CONNECTION_SYMBOL '#'

bool is_client_connection_close(const char* msg);

int main(int argc, char const* argv[]) {
    int client;
    struct sockaddr_in serverAddress;
    
    client = socket(AF_INET, SOCK_STREAM , 0);
	if(client < 0) {
		std::cout << "Server ERROR\n";
		return -1;
	}

    serverAddress.sin_port = htons(DEFAULT_PORT);
	serverAddress.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_IP, &serverAddress.sin_addr);
    std::cout << "\nClient socket Created.\n";
    int ret = connect(client, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if(ret == 0) {
        std::cout << "Connetction to server "
            << inet_ntoa(serverAddress.sin_addr) << " with port number: "
            << DEFAULT_PORT<< "\n";
    }
    char buffur[BUFFER_SIZE];
    std::cout << "Waiting for server confirmation...\n";
    recv(client, buffur, BUFFER_SIZE, 0);
    std::cout << "Connection established.\n"
    << "Enter " <<  SERVER_CLOSE_CONNECTION_SYMBOL << " to end the connection.\n\n";;
    
    while(true) {
        std::cout << "Client: ";
        std::cin.getline(buffur, BUFFER_SIZE);
        send(client, buffur, BUFFER_SIZE, 0);
        
        if(is_client_connection_close(buffur))
            break;

        std::cout << "Server: ";
        recv(client, buffur, BUFFER_SIZE, 0);
        std::cout << buffur;
        if(is_client_connection_close(buffur))
            break;

        std::cout << "\n";
    }
    close(client);
    std::cout << "\nGoodBye..."<<std::endl;
    return 0;
}

bool is_client_connection_close(const char* msg) {
	for(int i = 0; i < strlen(msg); ++i){
		if (msg[i] == SERVER_CLOSE_CONNECTION_SYMBOL){
			return true;
		}
	}
	return 0;
}