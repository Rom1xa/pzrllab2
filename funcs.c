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
    return '\0';
}


enum NumericalSystems getSys(char* str) {
    enum NumericalSystems numSys = UNKNOWN;
    int offset = 0;
    if (*str == '~')
        offset++;
    if (*(str + 1) == '-')
        offset++;

    if ((*(str + offset) == '1') && isValidNumber(str + offset, BIN)) {
        numSys = BIN;
    } else if ((*(str + offset) == '0' && *(str + offset + 1) == 'x') && isValidNumber(str + offset + 2, HEX)) {
        numSys = HEX;
    } else if ((*(str + offset) == '0') && isValidNumber(str + offset + 1, OCT)) {
        numSys = OCT;
    } else {
        return UNKNOWN;
    }


    switch (numSys) {
        case BIN:
            return BIN;
        case OCT:
            return OCT;
        case HEX:
            return HEX;
        default:
            return UNKNOWN;
    }
}

int isValidNumber(char* str, enum NumericalSystems nSys) {
    int i;
    unsigned long num = 0;
    if (nSys == HEX) {
        for (i = 0; str[i] != '\0'; ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + (str[i] - '0');
            } else if (str[i] >= 'a' && str[i] <= 'f') {
                num = num * 16 + (str[i] - 'a');
            } else {
                return 0;
            }
        }
    } else if (nSys == OCT) {
        for (i = 0; str[i] != '\0'; ++i) {
            if (str[i] >= '0' && str[i] <= '7') {
                num = num * 8 + (str[i] - '0');
            } else {
                return 0;
            }
        }
    } else if (nSys == BIN) {
        for (i = 0; str[i] != '\0'; ++i) {
            if (str[i] >= '0' && str[i] <= '1') {
                num = num * 2 + (str[i] - '0');
            } else {
                return 0;
            }
        }
    }

    return 1;
}