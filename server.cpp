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
        std::cout << "Error" << std::endl;
        exit(1);
    }

    SOCKADDR_IN addr;
    int size = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr("192.168.1.2");
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;


    SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
    bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
    listen(sListen, SOMAXCONN);

    SOCKET newConnection;
    newConnection = accept(sListen, (SOCKADDR*)&addr, &size);


    if (newConnection == 0)
    {
        std::cout << "Error";

    }

    else
    {

        std::cout << "connect";
        char msg[256] = "Sonay love";

        std::cout << send(newConnection, msg, sizeof(msg), NULL);

        recv(newConnection, msg, sizeof(msg), NULL);
        std::cout << msg << std::endl;

        Sleep(5000);
        closesocket(newConnection);
        std::cout<<send(newConnection, msg, sizeof(msg), NULL);

    }
    system("pause");
    return 0;
}
