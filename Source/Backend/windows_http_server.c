#include "windows_http_server.h"
#include <windows.h>
#include "Code/string.c"
#include "Code/memory.c"

#define PORT 8080
#define MAX_CONNECTION_COUNT 10

internal_function bool
InitializeSocket(SOCKET *ServerSocket)
{
    bool Result = 0;

    WSADATA WSAData = {0};
    int Error = WSAStartup(MAKEWORD(2, 2), &WSAData);
    if(Error != 0)
    {
        Log("WSAStartup() failed: %d\n", Error);
        return Result;
    }

    *ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(*ServerSocket == INVALID_SOCKET)
    {
        Log("socket() failed: %d", WSAGetLastError());
        WSACleanup();
        return Result;
    }

    struct sockaddr_in ServerAddress = {0};
    ServerAddress.sin_family = AF_INET;
    ServerAddress.sin_addr.S_un.S_addr = INADDR_ANY;
    ServerAddress.sin_port = LittleToBigEndianU16(PORT);

    Error = bind(*ServerSocket, (struct sockaddr *)&ServerAddress, sizeof(ServerAddress));
    if(Error == SOCKET_ERROR)
    {
        Log("bind() failed: %d", WSAGetLastError());
        closesocket(*ServerSocket);
        WSACleanup();
        return Result;
    }

    Error = listen(*ServerSocket, MAX_CONNECTION_COUNT   );
    if(Error == SOCKET_ERROR)
    {
        Log("listen() failed: %d", WSAGetLastError());
        closesocket(*ServerSocket);
        WSACleanup();
        return Result;
    }

    Result = 1;
    return Result;
}

int main(int ArgumentCount, char **Argument)
{
    int Result = 1;
    SOCKET ServerSocket;
    if(!InitializeSocket(&ServerSocket))
    {
        return Result;
    }

    for(;;)
    {
        struct sockaddr_in ClientAddress = {0};
        int ClientAddressLength = sizeof(ClientAddress);
        SOCKET ClientSocket = accept(ServerSocket, (struct sockaddr *)&ClientAddress, &ClientAddressLength);
        if(ClientSocket == INVALID_SOCKET)
        {
            Log("accept() failed: %d", WSAGetLastError());
            continue;
        }

        char Buffer[1024];
        int BytesReceived = recv(ClientSocket, Buffer, sizeof(Buffer) - 1, 0);
        if(BytesReceived == SOCKET_ERROR)
        {
            Log("recv() failed: %d", WSAGetLastError());
            break;
        }

        Buffer[BytesReceived] = '\0';

        Print("Request received:\n%s\n", Buffer);

        char *Response = 
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<html><body><h1>Hello, world!</h1><p>This is a simples http server</p></body></html>\r\n";

        send(ClientSocket, Response, (int)StringLength(Response), 0);
        
        Sleep(33);
    }

    closesocket(ServerSocket);
    WSACleanup();

    Result = 0;
    return Result;
}