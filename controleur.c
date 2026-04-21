#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "header.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    int sockfd = ssocket();
    

    char buffer[BUFFER_SIZE];
    if (argc != 3) {
        exit(1);
    }

    int port = atoi(argv[1]);
    char *ip = argv[2];
    sconnect(ip, port, sockfd);

    while (1) {
        ssize_t n = sread(0, buffer, sizeof(buffer) - 1);
        if (n <= 0) break;

        buffer[n] = '\0';  

        swrite(sockfd, buffer, n);  
    }

    sclose(sockfd);
    return 0;
}

