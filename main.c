#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[]) {
    size_t bufsize = 128;
    char* buf = malloc(bufsize * sizeof(char));
    size_t len = 0;
    char c;

    printf("Enter expression: ");
    do {
        c = getchar();
        if (!isspace(c)) {
            buf[len++] = c;
        } else if (len + 1 >= bufsize) {
            char* tmp = realloc(buf, bufsize * 2 * sizeof(char));
            if (tmp == NULL) {
                fprintf(stderr, "Error: Not enough memory.\n");
                exit(-1);
            }
            buf = tmp;
        }
    } while (c != '\n');

    buf[len++] = '\0';

    free(buf);
    return 0;
}
