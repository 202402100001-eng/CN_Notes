#include <bits/stdc++.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

int main()
{
    int server_socket;
    sockaddr_in server_address;

    server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    server_address.sin_family = AF_INET; 
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    ::bind(server_socket, (struct sockaddr *)& server_address, sizeof(server_address));

    char buffer[1024];
    socklen_t address_length = sizeof(server_address);
    int n = recvfrom(server_socket
    , buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&server_address, &address_length);

    buffer[n] = '\0';

    cout << "Recieved : " << buffer << endl;

    sendto(server_socket
    , buffer, n, 0, (struct sockaddr*)&server_address, address_length);

    close(server_socket);
    
    return 0; 
}