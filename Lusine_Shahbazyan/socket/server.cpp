#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <stdlib.h>
#define PORT 8080
#include <iostream>

int main(int argument, char const *argv[])
{
    int objServer, sock, reader;
    struct sockaddr_in address;
    int opted = 1;
    int addressLength = sizeof(address);
    char buffer[1024] = {0};
    char *message = "A message from server !";
    if((objServer = socket ( AF_INET, SOCK_STREAM, 0)) == 0)
    {
        std::cout << "Opening of Socket Failed !";
        exit (EXIT_FAILURE);
    }
    if(setsockopt(objServer, SOL_SOCKET, SO_REUSEADDR, &opted, sizeof ( opted )\
))

    {
        std::cout << "Can't set the socket";
        exit (EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    if (bind(objServer, ( struct sockaddr * )&address, sizeof(address)) < 0)
    {
        std::cout << "Binding of socket failed !";
        exit(EXIT_FAILURE);
    }
    if(listen ( objServer, 3) < 0)
    {
        std::cout << "Can't listen from the server !";
        exit(EXIT_FAILURE);
    }
    if((sock = accept(objServer, (struct sockaddr *)&address, (socklen_t*)&addr\
essLength)) < 0)
    {
        std::cout << "Accept";
        exit(EXIT_FAILURE);
    }
    reader = read(sock, buffer, 1024);
    std::cout << std::endl << buffer;
    send(sock, message, strlen(message), 0);
    std::cout << "Server : Message has been sent ! \n";
    return 0;
}

