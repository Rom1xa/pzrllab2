#include "funcs.h"

int main() {
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
    
    //printf("sys = %d, num = %d", getSys(buf), myStrToInt(buf, getSys(buf)));

    free(buf);
    return 0;
}
