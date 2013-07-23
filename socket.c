#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int ac, char *av[])
{
    int sock_desc;
    struct sockaddr_in server;
    char *request;
    char server_reply[2000];
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);

    if ( sock_desc == -1 ) {
        perror("can't creat socket:");
    } else {
        printf("socket created successful:%d\n", sock_desc);
    }

    server.sin_addr.s_addr = inet_addr("74.125.235.20");
    server.sin_family = AF_INET;
    server.sin_port = htons(80);

    if (connect(sock_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("can't connect to server");
        return 1;
    } else {
        printf("connected to server successfully\n");
    }

    request = "GET / HTTP/1.0\r\n\r\n";
    if (send(sock_desc, request, strlen(request), 0) < 0) {
        perror("can't send request\n");
        return 2;
    } else {
        printf("request send ok\n");
    }

    if (recv(sock_desc, server_reply, 2000, 0) < 0){
        perror("can't recv");
        return 3;
    } else {
        printf("recv ok:\n%s", server_reply);
    }

    close(sock_desc);
    return 0;
}
