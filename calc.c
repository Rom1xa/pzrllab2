#include "calc.h"

long long calcBin(char operation, long long firstNum, long long secondNum) {
    switch (operation)
    {
    case '+':
        return firstNum + secondNum;
        break;
    case '-':
        return firstNum - secondNum;
        break;
    case '*':
        return firstNum * secondNum;
        break;
    case '%':
        return firstNum % secondNum;
        break;
    case '&':
        return firstNum & secondNum;
        break;
    case '|':
        return firstNum | secondNum;
        break;
    case '^':
        return firstNum ^ secondNum;
        break;
    default:
        fprintf(stderr, "Invalid operator.\n");
        exit(-1);
        break;
    }
}

long long calcUno(char operation, long long firstNum) {
    if (operation != '~') {
        fprintf(stderr, "Invalid operator.\n");
        exit(-1);
    }
    return ~firstNum;
}