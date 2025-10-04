#ifndef app_h
#define app_h

#include <netinet/in.h>

struct App {
    int domain;
    int port;
    int service;
    int protocol;
    int queue;

    int socket;
    struct sockaddr_in address;
};

struct App build_app();

void serve(struct App *app);

#endif