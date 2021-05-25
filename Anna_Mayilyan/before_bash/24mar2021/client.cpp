#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

int main(int argc, char *argv[])
{
    int sock, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
		std::cout<<"ERROR using hostname port"<<std::endl;
       exit(0);
    }
    portno = atoi(argv[2]);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) 
		std::cout<<"ERROR while openning socket"<<std::endl;
    server = gethostbyname(argv[1]);
    if (server == NULL) {
		std::cout<<"ERROR, no host"<<std::endl;
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sock,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
		std::cout<<"ERROR during connecting"<<std::endl;
    printf("Please enter the message: ");
		std::cout<<"Enter the message"<<std::endl;
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sock,buffer,strlen(buffer));
    if (n < 0) 
		std::cout<<"ERROR while writing on socket"<<std::endl;
    bzero(buffer,256);
    n = read(sock,buffer,255);
    if (n < 0) 
		std::cout<<"ERROR while reading socket"<<std::endl;
		std::cout<<buffer<<std::endl;
    close(sock);
    return 0;
}
