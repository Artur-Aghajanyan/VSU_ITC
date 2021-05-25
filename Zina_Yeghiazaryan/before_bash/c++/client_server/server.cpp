#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main (int argc, char *argv[]) {
   int s;
   int t;
   int portNum = 9006;
   struct sockaddr_in servAddr;
   char msg[80];
  
   if ( (s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      std :: cout << "error1";
      return -1;
   }
  
   servAddr.sin_family = AF_INET;
   servAddr.sin_port = htons(portNum);
   servAddr.sin_addr.s_addr = INADDR_ANY;
  
   if (bind (s, (struct sockaddr *) &servAddr, sizeof(servAddr) ) < 0) {
      std::cout << "error2";
      return -1;
   }
  
   if (listen (s, 5)) {
      std :: cout << "error3";
      return -1;
   }
  
   socklen_t clilen = sizeof(servAddr);
  
   while (1) {
      if ( (t = accept(s, (struct sockaddr *) &servAddr, &clilen) ) < 0 ) {
         std::cout << "error4";
         return -1;
      } else {
         std::cout << "success accept" << std::endl;
      }
     
      printf( "From %s:%d.\n", inet_ntoa(servAddr.sin_addr), ntohs(servAddr.sin_port) );
     
      if ((recv(t, msg, 80, 0)) < 0) {
         std::cout << "error5";
         return -1;
      }
      std::cout << "recieved message: " << msg << std::endl;
     
      if ((send(t, msg, 80, 0)) < 0) {
         std::cout << "error6";
         return -1;
      }
   }
  
   if (close(s) < 0) {
        return -1;
   }
   return 0;
}
