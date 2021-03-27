#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <iostream>
#define PORT 8507

int main()
{
    int server, sock;
    struct sockaddr_in serverAddr;
    int newSocket;
    struct sockaddr_in newAddr;
    socklen_t addr_size;
    char buffer[1024];
    pid_t childpid;
    server = socket(AF_INET, SOCK_STREAM, 0);
    if(server < 0)
    {
        std::cout << "Error in connection.\n";
	exit(1);
    }
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sock = bind(server, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(sock < 0)
    {
        std::cout << "Error in binding.\n";
	exit(1);
    }
    if(listen(server, 10) == 0)
    {
        std::cout << "Listening....\n";
	} else {
        std::cout << "Error in binding.\n";
	}
	while(1)
	{
	    newSocket = accept(server, (struct sockaddr*)&newAddr, &addr_size);
            if(newSocket < 0)
            {
		exit(1);
	    }
            std::cout << "Connection accepted.\n";
      	    if((childpid = fork()) == 0)
            {
		close(server);
       	        while(1)
                {
		    if(strcmp(buffer, "exit") == 0)
                    {
                        std::cout << "\n Disconnected \n";
                        break;
		    } else {
                        recv(newSocket, buffer, 1024, 0);
                        std::cout << "Client :  ";
                        std::cout << buffer;
                        std::cout << "\nServer :  ";
                        std::cin.getline(buffer, 1024);
                        send(newSocket, buffer, strlen(buffer), 0);
			bzero(buffer, sizeof(buffer));
		    }
		}
            }
	}
	close(newSocket);
	return 0;
}
