#include<iostream>
#include<string.h>
#include<winsock2.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

int main(){
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in server, client;
    char buffer[1024];
    int clientLen;

    WSAStartup(MAKEWORD(2,2), &wsa);
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family      = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port        = htons(8080);
    bind(serverSocket,(struct sockaddr*)&server, sizeof(server));
    listen(serverSocket, 1);

    cout << "Server listening on port 8080..." << endl;
    clientLen    = sizeof(client);
    clientSocket = accept(serverSocket,(struct sockaddr*)&client,&clientLen);
    cout << "Client connected!" << endl;

    while(true){
        memset(buffer, 0, sizeof(buffer));
        int bytes = recv(clientSocket, buffer, sizeof(buffer), 0);
        if(bytes <= 0) break;
        cout << "Client: " << buffer << endl;
        if(string(buffer) == "exit") break;

        string reply;
        cout << "Enter reply: ";
        getline(cin, reply);
        send(clientSocket, reply.c_str(), reply.length(), 0);
        if(reply == "exit") break;
    }

    cout << "Connection closed." << endl;
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
