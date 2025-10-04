#ifndef client_h
#define client_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>


struct Client {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
    int *client_fd;
};

struct Client build_client();

#endif