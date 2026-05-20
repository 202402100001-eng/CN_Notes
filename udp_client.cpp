#include <bits/stdc++.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;


int main()
{
    int client_socket;
    sockaddr_in server_address;

    client_socket = socket(AF_INET, SOCK_DGRAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr);

    char *msg = "Hello from udp server";
    sendto(client_socket, msg, strlen(msg), 0, (struct sockaddr *)&server_address, sizeof(server_address));

    char buffer[1024] = {0};
    sockaddr_in from_address; 
    socklen_t from_length;

    int n = recvfrom(client_socket, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&from_address, &from_length);
    buffer[n] = '\0';
    cout << "server replied : " << buffer << endl;

    close(client_socket);

    return 0;
}