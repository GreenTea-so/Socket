#pragma comment(lib, "ws2_32.lib")
#include<winsock2.h>
#include <iostream>
#include<windows.h>

#pragma warning(disable:4996)
int main()
{
    //WSAStartup
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        std::cout << "Error1" << std::endl;
        exit(1);
    }

    SOCKADDR_IN addr;
    int size = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("192.168.1.2");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;

    SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
    if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
    {
        std::cout << "Error";
        return 0;
    }
    else
    {
        std::cout << "Connect";
        char msg[256];
        
        recv(Connection, msg, sizeof(msg), NULL);
        std::cout << msg << std::endl;

        char msg2[256]="Client";
        send(Connection, msg2, sizeof(msg), NULL);
        closesocket(Connection);
    }

    system("pause");
    return 0;
}