#include "client.h"
#include "../router/router.h"

struct client make_client() {

    struct client client;

    client.client_addr_len = sizeof(client.client_addr);
    client.client_fd = malloc(sizeof(int));
    client.buffer_size = 104857600;

    return client;
}

char *receive_data(struct client *client) {

    char *buffer = (char *)malloc(client->buffer_size * sizeof(char));

    // receive request data from client and store into buffer
    ssize_t bytes_received =
        recv(*client->client_fd, buffer, client->buffer_size, 0);

    printf("%s\n", buffer);

    return buffer;
}

char *parse_method(char *request) {
    char firstLine[100];
    char *a = strchr(request, '\n');

    size_t length = a - request;

    strncpy(firstLine, request, length);

    printf("FIRST LINE %s\n", firstLine);

    char *buffer = (char *)malloc(10 * sizeof(char));

    length = strchr(firstLine, ' ') - firstLine;

    strncpy(buffer, firstLine, length);

    printf("METHOD %s\n", buffer);

    return buffer;
}

char *parse_path(char *request) {

    char firstLine[100];
    char *a = strchr(request, '\n');

    size_t length = a - request;

    strncpy(firstLine, request, length);

    printf("FIRST LINE %s\n", firstLine);

    char *buffer = (char *)malloc(10 * sizeof(char));

    char *skip =strchr(firstLine, ' ')+1;

    length = strchr(skip, ' ') - skip;

    strncpy(buffer, skip, length);

    printf("PATH %s\n", buffer);

    return buffer;
}

void send_response(struct client *client, char *response) {

    send(*client->client_fd, response, (size_t)10000, 0);

    close(*client->client_fd);
}
