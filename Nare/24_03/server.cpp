#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <netdb.h>
#include <netinet/in.h>

#include <iostream>

int main(int argc, char* argv[]) {
    int open_socket, binding, port_num, caddrlen, accept_int;
    struct sockaddr_in server_address, client_address;
    char msg[256];
    int n;

    open_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(open_socket < 0) {
        std::cout << "Error opening socket" << std::endl;
        return -1;
    }
    bzero((char *) &server_address, sizeof(server_address));
    port_num = 7000;

    server_address.sin_family = AF_INET; //IP4
    server_address.sin_port = htons(port_num); //port
    server_address.sin_addr.s_addr = INADDR_ANY;//ip address will be assigned automatically
    
    binding = bind(open_socket, (struct sockaddr*)&server_address, sizeof(server_address));
    if(binding < 0) {
        std::cout << "Binding error " << std::endl;
        return -1;
    }

    listen(open_socket, 5);
    caddrlen = sizeof(client_address);

    accept_int = accept(open_socket, (struct sockaddr*)&client_address,(socklen_t*) &caddrlen);
    if(accept_int < 0) {
        std::cout << "Acceptance error" << std::endl;
        return -1;
    }
    
    bzero(msg,256);
    n = read(accept_int, msg, 255);
    
    if(n < 0) {
        std::cout << "Reading error" << std::endl;
        return -1;
    }

    std::cout << "Message: " << msg << std::endl;
    n = write(accept_int, "Message has been accepted!!!", 28);

    if(n < 0) {
        std::cout << "Writing error" <<std::endl;
        return -1;
    }

    return 0;
}
