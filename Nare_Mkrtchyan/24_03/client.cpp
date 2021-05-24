#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
   
int main(int argc, char const *argv[])
{
    int sock, n, port_num = 7000;
    struct sockaddr_in server_address;
    char *hello = "Hello from client";
    char msg[256];
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cout << "Socket creation error \n" << std::endl;
        return -1;
    }
   
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_num);
       
    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        std::cout << "Connection error" << std::endl;
        return -1;
    }
    n = send(sock , hello , strlen(hello) , 0 );

    if(n < 0) {
        std::cout << "sending error" <<std::endl;
        return -1;
    }
    std::cout << "Message has been sent" << std::endl;

    n = read( sock , msg, 256);
    if(n < 0) {
        std::cout << "Reading error" <<std::endl;
        return -1;
    }

    std::cout << msg <<std::endl;
    return 0;
}
