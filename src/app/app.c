#include "../app/app.h"
#include "../client/client.h"
#include "../router/router.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct app make_app() {

    struct app app;

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

    struct router router = make_router();

    app.router = router;


    return app;
}

typedef void (*nothing)();

void ha() {};

void serve(struct app *app) {

    struct client client = make_client();

    printf("listening\n");

    while (1) {

        accept_connection(app, &client);

        printf("connection accepted\n");

        char *in = receive_data(&client);

        char *r = (char *)malloc(104857600 * sizeof(char));

        handler handler = redirect(&app->router, "GET", "/health");

        (*handler)(in, r);

        free(in);

        send_response(&client, r);
    }
}

void accept_connection(struct app *app, struct client *client) {

    *client->client_fd =
        accept(app->socket, (struct sockaddr *)&client->client_addr,
               &client->client_addr_len);

    // accept client connection
    if (*client->client_fd < 0) {
        perror("accept failed");
        printf("%d", app->socket);
        return;
    }
}