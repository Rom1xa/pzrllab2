#include "calc.h"

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
    if (*(str + offset) == '-')
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

long long myStrToInt(char *str, enum NumericalSystems nSys) {
    if (nSys == UNKNOWN) {
        fprintf(stderr, "Invalid numerical system specified.\n");
        exit(-1);
    }
    
    int offset = 0;
    if (*str == '-')
        offset++;
    if (*(str + offset) == '~')
        offset++;

    switch (nSys) {
        case HEX:
            offset += 2;
            break;
        case OCT:
            offset += 1;
            break;
        default:
            break;
    }
    char *num = str + offset;
    long long result = 0;
    size_t len = strlen(num);

    for (size_t i = 0; i < len; ++i) {
        result += charToInt(num[i]) * pow(nSys, len-i - 1);
    }

    return result;
}

int charToInt(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    } else if (ch >= 'a' && ch <= 'f') {
        return ((ch - 'a') + 10);
    } else {
        return -1;
    }
}

Number getNum(char *str) {
    Number n;
    n.nSys = getSys(str);
    n.intNum = myStrToInt(str, n.nSys);
    n.num = str;
    if (str[0] == '-') {
        n.sign = -1;
    } else {
        n.sign = 1;
    }
    return n;
}
void decToHex(long long dec) {
    long long tmp = dec;
    if (dec < 0) {
        printf("-");
        dec = dec * (-1);
    }
    char hex[128];
    int i = 0;
    while (dec != 0) {
        long long remainder = dec % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0';
        } else {
            hex[i] = remainder - 10 + 'a';
        }
        i++;
        dec = dec / 16;
    }
    printf("0x");
    if (tmp == 0) {
        printf("0");
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

void decToOctal(long long dec) {
    long long tmp = dec;
    if (dec < 0) {
        printf("-");
        dec = dec * (-1);
    }
    int octalNum[128];
    int i = 0;
    while (dec != 0) {
        octalNum[i] = dec % 8;
        dec = dec / 8;
        i++;
    }
    printf("0");
    if (tmp == 0) {
        printf("0");
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octalNum[j]);
    }
}

void decToBinary(long long dec) {
    if (dec == 0) {
        printf("0");
    }
    if (dec < 0) {
        printf("-");
        dec = dec * (-1);
    }
    int binaryNum[128];
    int i = 0;
    while (dec > 0) {
        binaryNum[i] = dec % 2;
        dec = dec / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNum[j]);
    }
}

void printResult(long long result,enum NumericalSystems nSys) {
    if (nSys == BIN) {
            decToBinary(result);
            printf(" (%lld)\n", result);
        } else if (nSys == OCT) {
            decToOctal(result);
            printf(" (%lld)\n", result);
        } else if (nSys == HEX) {
            decToHex(result);
            printf(" (%lld)\n", result);
        }
}