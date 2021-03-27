#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#define PORT 8507

int main()
{
    int client, sock;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    client = socket(AF_INET, SOCK_STREAM, 0);
    if(client < 0)
    {
        std::cout << "Error in connection.\n";
	exit(1);
    }
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sock = connect(client, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(sock < 0)
    {
        std::cout << "Error in connection.\n";
	exit(1);
    }
    while(1)
    {
        if(strcmp(buffer, "exit") == 0)
        {
	    close(client);
            std::cout << "\n Disconnected \n";
	    exit(1);
            break;
	}
        std::cout << "\nClient :  ";
        std::cin.getline(buffer, 1024);
	send(client, buffer, strlen(buffer), 0);
        bzero(buffer, sizeof(buffer));
        recv(client, buffer, 1024, 0);
        std::cout << "Server :  ";
        std::cout << buffer;
    }
    return 0;
}
