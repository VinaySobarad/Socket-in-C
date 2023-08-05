#include<winsock2.h>
#include<ws2tcpip.h>
#include<stdio.h>
#pragma comment(lib, ws2_32.lib);

int mani(){


    SOCKET client_socket;   //creates a socket dtructure
    WSADATA wsastructure;   //creates a wsadata structure required for winsock intialization
    int result ;
    struct sockaddr_in client_addr;  //create a structure required by the connect()
    char sendData[500]= "Hello form the client";
    char recvData[500];


    result= WSAStartup(MAKEWORD(2, 2), &wsastructure);  //Intialization winsock
    if(result != 0){
        printf("[!] Winsock intialization failed"); //print out the error and exit out the program
        return 1;
    }

    client_socket= socket(AF_INET, SOCK_STREAM, 0);
    client_addr.sin_family = AF_INET;      //Declaring the type
    client_addr.sin_port = htons(9001);     // Declaring the port number
    client_addr.sin_addr.s_addr= inet_addr("");     // Declaring the host

    connect(client_socket, (SOCKADDR*) &client_addr, sizeof(client_addr) );

    recv(client_socket,recvData, sizeof(recvData), 0 );
    printf("Data from the server:%s\n", recvData);
    send(client_socket, sendData, sizeof(sendData), 0);

    closesocket(client_socket);
    WSACleanup();
    return 0;
}
