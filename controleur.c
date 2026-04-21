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
  sconnect(LOCAL_HOST, SERVER_PORT, sockfd);
  char buffer[BUFFER_SIZE];
  int nbCharRd = read(1, buffer, BUFFER_SIZE);
  while (nbCharRd > 0) {
    int nbCharWr = write(1, bufRd, nbCharRd);
    checkCond(nbCharWr != nbCharRd,"Error writing stdout");
    nbCharRd = read(fd, bufRd, BUFFER_SIZE);
  }
  checkNeg(nbCharRd,"Error reading file");



  swrite(sockfd,&buffer,sizeof(int));
  sclose(sockfd);
    return 0;
}