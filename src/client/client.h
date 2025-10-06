#ifndef client_h
#define client_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include "../router/router.h"


struct Client {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
    int *client_fd;
    u_int32_t buffer_size;
};

struct Client build_client();

char* receive_data(struct Client *client);

void send_response(struct Client *client, char *response);

void handle(struct Client *client, struct router *router);

#endif