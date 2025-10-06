#ifndef app_h
#define app_h

#include "../client/client.h"
#include "../router/router.h"
#include <netinet/in.h>

struct app {
    int domain;
    int port;
    int service;
    int protocol;
    int queue;

    int socket;
    struct sockaddr_in address;

    struct router router;
};

struct app make_app();

void serve(struct app *app);

void accept_connection(struct app *app, struct client *client);

#endif