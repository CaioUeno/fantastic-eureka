#ifndef router_h
#define router_h

#define METHOD_MAX_SIZE 10
#define PREFIX_MAX_SIZE 100
#define ROUTES_MAX_SIZE 200

typedef void (*handler)(char *in, char *out);

struct route {
    char *method;
    char *prefix;
    handler handler;
};

struct router {
    struct route *routes[ROUTES_MAX_SIZE];
    int last_route_idx;
};

struct router make_router();
void add_route(struct router *router, handler new_handler, char *method,
               char *prefix);
handler redirect(struct router *router, char* method, char *prefix);

#endif