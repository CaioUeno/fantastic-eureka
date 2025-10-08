#include "router.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct router make_router() {

    struct router router;

    router.last_route_idx = 0;

    return router;
}

void add_route(struct router *router, handler new_handler, char *method,
               char *prefix) {

    struct route *route = (struct route *)malloc(sizeof(struct route));

    route->method = (char *)malloc(METHOD_MAX_SIZE * sizeof(char));
    strncpy(route->method, method, METHOD_MAX_SIZE);

    route->prefix = (char *)malloc(PREFIX_MAX_SIZE * sizeof(char));
    strncpy(route->prefix, prefix, PREFIX_MAX_SIZE);

    route->handler = *new_handler;

    router->routes[router->last_route_idx++] = route;
}

handler redirect(struct router *router, char *method, char *prefix) {

    printf("REDIRECT\n");

    for (int i = 0; i < 10; i++) {
        printf("Route %d\n", i);
        printf("method %s\n", router->routes[i]->method);

        int is_method_equal = strcmp(router->routes[0]->method, method);
        if (is_method_equal == 0) {
            return router->routes[0]->handler;
        }
    }
}
