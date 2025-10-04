#include "app.h"
#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct App build_app() {

    struct App app;

    app.domain = AF_INET;
    app.port = 8090;
    app.service = SOCK_STREAM;
    app.protocol = 0;
    app.queue = 10;
    app.socket = socket(app.domain, app.service, 0);

    if (app.socket == -1) {
        printf("error");
        exit(EXIT_FAILURE);
    }

    // config socket
    app.address.sin_family = app.domain;
    app.address.sin_addr.s_addr = INADDR_ANY;
    app.address.sin_port = htons(app.port);

    int bind_success =
        bind(app.socket, (struct sockaddr *)&app.address, sizeof(app.address));

    if (bind_success < 0) {
        printf("error");
        exit(EXIT_FAILURE);
    }

    int listen_success = listen(app.socket, app.queue);

    if (listen_success < 0) {
        printf("error");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", 8090);

    return app;
}

void serve(struct App *app) {

    struct Client client = build_client();
    
    while (1) {

        // accept client connection
        if ((*client.client_fd = accept(app->socket, (struct sockaddr *)&client.client_addr,
                                 &client.client_addr_len)) < 0) {
            perror("accept failed");
            printf("%d", app->socket);
            return;
        }

        char *buffer = (char *)malloc(104857600 * sizeof(char));

        // receive request data from client and store into buffer
        ssize_t bytes_received = recv(*client.client_fd, buffer, 104857600, 0);

        printf("%s", buffer);

        // build HTTP response
        // char *response = (char *)malloc(104857600 * 2 * sizeof(char));
        // size_t response_len;
        // build_http_response(file_name, file_ext, response, &response_len);

        char response[10000] = "HTTP/1.1 200 OK\r\n"
                               "Content-Type: application/json\r\n"
                               "\r\n"
                               "{success: true}\r\n";

        // send HTTP response to client
        send(*client.client_fd, response, (size_t)10000, 0);

        close(*client.client_fd);

        // // create a new thread to handle client request
        // pthread_t thread_id;
        // pthread_create(&thread_id, NULL, handle_client, (void *)client_fd);
        // pthread_detach(thread_id);
    }
}