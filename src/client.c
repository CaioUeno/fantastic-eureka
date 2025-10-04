#include "client.h"

struct Client build_client() {

    struct Client client;

    client.client_addr_len = sizeof(client.client_addr);
    client.client_fd = malloc(sizeof(int));

    return client;
}