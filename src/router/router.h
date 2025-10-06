#ifndef router_h
#define router_h

typedef void (*handler)(char *in, char *out);

struct route {
    char *method;
    char *prefix;
    handler handler;
};

struct router {
    struct route *route;
};

struct router make_router();
void add_route(struct router *router, handler new_handler);

#endif