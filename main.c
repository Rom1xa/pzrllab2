#include "calc.h"

int main() {
    size_t bufsize = 128;
    char* buf = malloc(bufsize * sizeof(char));
    size_t len = 0;
    char c;

    printf("Enter expression: ");
    do {
        c = getchar();
        if (c == *" ") {
            buf[len++] = *" ";
        } else if (!isspace(c)) {
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

    char **tokens = malloc(3 * sizeof(char*));
    for (int i = 0; i < 3; ++i)
        tokens[i] = NULL;

    char *pt = strtok(buf, " ");
    int count = 0;
    while (pt != NULL) {
        tokens[count++] = pt;
        pt = strtok(NULL, " ");
    }

    if (count == 3) {
        Number n1, n2;
        n1 = getNum(tokens[0]);
        n2 = getNum(tokens[2]);
        char operator = *tokens[1];
        long long result;
        result = calcBin(operator, n1.intNum, n2.intNum);
        if (n1.nSys != n2.nSys) {
            perror("different systems\n");
            exit(-1);
        } else {
            printResult(result, n1.nSys);
        }
    } else if (count == 2) {
        Number n1;
        n1 = getNum(tokens[1]);
        char operator = *tokens[0];
        if (operator != '~') {
            perror("invalid operator\n");
            exit(-1);
        }
        long long result;
        result = calcUno(operator, n1.intNum);
        printResult(result, n1.nSys);

    } else if (count == 1 && tokens[0][0] != '~') {
        perror("not enough values\n");
        exit(-1);
    } else if (count == 1 && tokens[0][0] == '~') {
        Number n1;
        n1 = getNum(tokens[0]);
        char operator = tokens[0][0];
        long long result = calcUno(operator, n1.intNum);
        printResult(result, n1.nSys);
    }

    free(buf);
    return 0;
}
