#ifndef router_h
#define router_h

typedef void (*handler)(char *in, char *out);

struct route {
    char *method;
    char *prefix;
    handler handler;
};

struct router {
    struct route *routes[10];
};

struct router make_router();
void add_route(struct router *router, handler new_handler, char *method,
               char *prefix);
handler redirect(struct router *router, char* method, char *prefix);

#endif