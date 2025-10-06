#include <stdio.h>
#include <string.h>

void health_handler(char *in, char *out) {
    printf("QQQQQQ\n\n");

    char *r = "HTTP/1.1 500 Bad Request\r\n"
                     "Content-Type: application/json\r\n"
                     "\r\n"
                     "'{message: 'down!'}'\r\n";

    strncpy(out, r, 1000);
    out[999] = '\0';
    
}