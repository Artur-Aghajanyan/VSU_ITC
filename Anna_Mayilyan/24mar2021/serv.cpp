#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc, char *argv[])
{
     int sock, newsock, portno;
     socklen_t clilent;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
		std::cout<<"Error, no port"<<std::endl;
        exit(1);
     }
     sock = socket(AF_INET, SOCK_STREAM, 0);
     if (sock < 0) 
		std::cout<<"ERROR while openning socket"<<std::endl;

     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sock, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
				std::cout<<"Error during binding"<<std::endl;
     listen(sock,5);
     clilent = sizeof(cli_addr);
     newsock = accept(sock, 
                 (struct sockaddr *) &cli_addr, 
                 &clilent);
     if (newsock < 0) 
	 std::cout<<"Error during accept"<<std::endl;
     bzero(buffer,256);
     n = read(newsock,buffer,255);
     if (n < 0)
	 std::cout<<"ERROR while reding from socket"<<std::endl;
     std::cout<<"This is the message"<<buffer<<std::endl;
     n = write(newsock,"I got your message",18);
     if (n < 0) 
	 std::cout<<"Error while writing on socket"<<std::endl;
     close(newsock);
     close(sock);
     return 0; 
}
