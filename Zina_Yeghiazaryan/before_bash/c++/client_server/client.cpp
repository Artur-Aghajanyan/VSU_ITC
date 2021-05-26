#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main (int argc, char const *argv[]) {
    int Socket, sinlen, portNum = 9006;
    struct hostent *hptr;
    struct sockaddr_in servAddr;
    char* hello="Heeeloooo Wooorld";
    char msg[80];
  
    if( (Socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std :: cout << "error1";
        return -1;
    }
  
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(portNum);
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  
//    if ( (hptr =  gethostbyname(argv[1]) ) == NULL){
//       fprintf(stderr, "gethostname error: %s", argv[1]);
//       return -1;
//    }
//    memcpy( &servAddr.sin_addr, hptr->h_addr, hptr->h_length);
  
    if (connect (Socket, (struct sockaddr *) &servAddr, sizeof(servAddr) ) < 0) {
        std::cout << "error2";
        return -1;
    }
  
    while(1){
        if ((send(Socket, hello, sizeof(hello), 0)) < 0) {
            std::cout << "error3";
            return -1;
        }
      
        if ((recv(Socket, msg, sizeof(msg), 0)) < 0) {
           std :: cout << "error4";
           return -1;
        }
      
        if (close(Socket) < 0) {
           return -1;
        }
    }
  
    return 0;
}
