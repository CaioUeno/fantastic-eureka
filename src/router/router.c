#include "router.h"
#include <stdio.h>
#include <stdlib.h>

struct router make_router() {
    printf("hey\n");
    struct route *route = (struct route *)malloc(sizeof(struct route));
    struct router router;
    router.route = route;

    printf("ha\n");

    return router;
}

void add_route(struct router *router, handler new_handler) {
    router->route->handler = *new_handler;
}
