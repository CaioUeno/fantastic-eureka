#include "router.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct router make_router() {
    printf("hey\n");
    struct route *route = (struct route *)malloc(10 * sizeof(struct route));
    route->method = (char *)malloc(20 * sizeof(char));
    route->prefix = (char *)malloc(20 * sizeof(char));

    struct router router;
    router.routes[0] = route;

    printf("ha\n");

    return router;
}

void add_route(struct router *router, handler new_handler, char *method,
               char *prefix) {

    printf("AQUI\n");
    printf("%p\n\n", router->routes[0]->method);

    strncpy(router->routes[0]->method, method, 20);
    strncpy(router->routes[0]->prefix, prefix, 20);
    router->routes[0]->handler = *new_handler;
}

handler redirect(struct router *router, char *method, char *prefix) {

    printf("REDIRECT\n");

    for (int i = 0; i < 10; i++) {
        printf("Route %d\n", i);

        int is_method_equal = strcmp(router->routes[0]->method, method);
        if (is_method_equal == 0) {
            return router->routes[0]->handler;
        }
    }
}
