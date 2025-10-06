#ifndef app_h
#define app_h

#include <netinet/in.h>
#include "../client/client.h"
#include "../router/router.h"
struct App {
    int domain;
    int port;
    int service;
    int protocol;
    int queue;

    int socket;
    struct sockaddr_in address;

    struct router router;
};

struct App build_app();

void serve(struct App *app);

void accept_connection(struct App *app, struct Client *client);

#endif