#include "client.h"
#include "../router/router.h"
struct Client build_client() {

    struct Client client;

    client.client_addr_len = sizeof(client.client_addr);
    client.client_fd = malloc(sizeof(int));
    client.buffer_size = 104857600;

    return client;
}

char *receive_data(struct Client *client) {

    char *buffer = (char *)malloc(client->buffer_size * sizeof(char));

    // receive request data from client and store into buffer
    ssize_t bytes_received =
        recv(*client->client_fd, buffer, client->buffer_size, 0);

    printf("%s\n", buffer);

    return buffer;
}

void send_response(struct Client *client, char *response) {

    send(*client->client_fd, response, (size_t)10000, 0);

    close(*client->client_fd);
}

void handle(struct Client *client, struct router *router) {
    printf("HANDLE\n");
    
    char *in = receive_data(client);

    printf("%p\n", router->route->handler);

    printf("HANDLE\n");

    char response[1000];
    char *r = response;

    // handler handler = redirect(router, method, prefix);

    // r = (*router->route->handler)(in, r);

    free(in);
    char *out = "HTTP/1.1 200 OK\r\n"
                "Content-Type: application/json\r\n"
                "\r\n"
                "'{message: 'up and running!'}'\r\n";

    send_response(client, out);
}