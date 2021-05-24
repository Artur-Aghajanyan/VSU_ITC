#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#define PORT 8080

int main (int argument, char const *argv[])
{
    int objSocket = 0, reader;
    struct sockaddr_in servAddr;
    char *message = "A message from Client !";
    char buffer[1024] = {0};
    if ((objSocket = socket (AF_INET, SOCK_STREAM, 0 )) < 0)
    {
        std::cout << "Socket creation error !";
        return -1;
    }
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);
    if(inet_pton ( AF_INET, "127.0.0.1", &servAddr.sin_addr)<=0)
    {
        std::cout <<"\nInvalid address ! This IP Address is not supported !\n";
        return -1;
    }
    if(connect(objSocket, (struct sockaddr *)&servAddr, sizeof(servAddr )) < 0)
    {
        std::cout <<"Connection Failed : Can't establish a connection over this\
 socket !"<< std::endl;
        return -1;
    }
    send (objSocket, message, strlen(message), 0);
    std::cout << "\nClient : Message has been sent !\n";
    reader = read ( objSocket, buffer, 1024 );
    std::cout << std::endl << buffer;
    return 0;
}

