#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
int main(void) {
    int sockfd;
    struct sockaddr saddr;
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    bind(sockfd,
