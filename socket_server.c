#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>


int main(){
          int server_socket;  // Used for creating socket
          int client_socket;   //used for accepting connections
          struct sockaddr_in server_addr;   //structure by the bind()
          char buffer[500] = "hello from the server";
          char rcv_buffer[500];
          
          server_socket= socket(AF_INET, SOCK_STREAM, 0);   //creates a tcp socket
          
          server_addr.sin_family = AF_INET;      //Declaring the type
          server_addr.sin_port = htons(9001);     // Declaring the port number
          server_addr.sin_addr.s_addr= inet_addr("");     // Declaring the host
                    
          bind(server_socket, (struct server_addr*) &server_addr, sizeof(server_addr)); //Bind the server
          listen(server_socket, 5);
          
          client_socket= accept(server_socket, NULL, NULL);  //Accept incoming connections
          printf("Client connected\n");
          send(client_socket, buffer, sizeof(buffer), 0);      //Sending data to client
          
          recv(client_socket, rcv_buffer, sizeof(rcv_buffer), 0);       //Recv data from the client
          printf("Client has sent: %s",rcv_buffer);                 // Print out the data sent by client
          close(server_socket);   //Close connections
          return 0;
       
}

