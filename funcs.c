#include "funcs.h"

char getOp(char *str) {
    int i;
    for (i = 0; str[i]; ++i) {
        switch (str[i]) {
            case '+':
                return '+';
            case '-':
                return '-';
            case '*':
                return '*';
            case '%':
                return '%';
            case '~':
                return '~';
            case '|':
                return '|';
            case '^':
                return '^';
            case '&':
                return '&';
            default:
                continue;
        }
    }
    return '\0'; // no operator found
}