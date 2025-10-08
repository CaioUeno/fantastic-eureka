#include "src/app/app.h"
#include "src/handlers/handlers.h"
#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    struct app app = make_app();

    add_route(&app.router, health_handler, "GET", "/health");

    serve(&app);

    close(app.socket);

    return 0;
}