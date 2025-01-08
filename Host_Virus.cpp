#include <iostream>
#include <string>
#include <winsock2.h> 
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void sendCommandToVM(const string& command) {
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;
    char serverIP[] = "192.168.18.245"; 
    int port = 8080;

    cout << "Initializing Winsock..." << endl;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        cout << "Winsock initialization failed. Error: " << WSAGetLastError() << endl;
        return;
    }

    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        cout << "Could not create socket. Error: " << WSAGetLastError() << endl;
        return;
    }

    server.sin_addr.s_addr = inet_addr(serverIP);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    cout << "Connecting to the VM..." << endl;
    if (connect(s, (struct sockaddr*)&server, sizeof(server)) < 0) {
        cout << "Connection failed. Error: " << WSAGetLastError() << endl;
        closesocket(s);
        WSACleanup();
        return;
    }

    cout << "Sending command to VM..." << endl;
    if (send(s, command.c_str(), command.size(), 0) < 0) {
        cout << "Command failed to send. Error: " << WSAGetLastError() << endl;
    }

    cout << "Command sent!" << endl;
    closesocket(s);
    WSACleanup();
}

int main() {
    while (true) {
        string command;
        cout << "Enter the virus command to activate on the VM: ";
        cin >> command;

        sendCommandToVM(command);
    }

    return 0;
}
