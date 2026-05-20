#include<iostream>
#include<string.h>
#include<winsock2.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

int main(){
    WSADATA wsa;
    SOCKET clientSocket;
    struct sockaddr_in server;
    char buffer[1024];

    WSAStartup(MAKEWORD(2,2), &wsa);
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family      = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port        = htons(8080);
    connect(clientSocket,(struct sockaddr*)&server, sizeof(server));
    cout << "Connected to server!" << endl;

    while(true){
        string message;
        cout << "Enter message: ";
        getline(cin, message);
        send(clientSocket, message.c_str(), message.length(), 0);
        if(message == "exit") break;

        memset(buffer, 0, sizeof(buffer));
        recv(clientSocket, buffer, sizeof(buffer), 0);
        cout << "Server: " << buffer << endl;
        if(string(buffer) == "exit") break;
    }

    cout << "Connection closed." << endl;
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
