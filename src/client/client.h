#ifndef client_h
#define client_h

#include "../router/router.h"
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct client {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
    int *client_fd;
    u_int32_t buffer_size;
};

struct client make_client();

char *receive_data(struct client *client);

void send_response(struct client *client, char *response);

void handle(struct client *client, struct router *router);

#endif