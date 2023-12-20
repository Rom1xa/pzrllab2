#include "calc.h"

long long calcBin(char operation, Number firstNum, Number secondNum) {
    firstNum.intNum *= firstNum.sign;
    secondNum.intNum *= secondNum.sign;
    switch (operation)
    {
    case '+':
        return firstNum.intNum + secondNum.intNum;
        break;
    case '-':
        return firstNum.intNum - secondNum.intNum;
        break;
    case '*':
        return firstNum.intNum * secondNum.intNum;
        break;
    case '%':
        return firstNum.intNum % secondNum.intNum;
        break;
    case '&':
        return firstNum.intNum & secondNum.intNum;
        break;
    case '|':
        return firstNum.intNum | secondNum.intNum;
        break;
    case '^':
        return firstNum.intNum ^ secondNum.intNum;
        break;
    default:
        fprintf(stderr, "Invalid operator.\n");
        exit(-1);
        break;
    }
}

long long calcUno(char operation, Number firstNum) {
    if (operation != '~') {
        fprintf(stderr, "Invalid operator.\n");
        exit(-1);
    }
    return ~firstNum.intNum;
}