#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

enum NumericalSystems {
    BIN = 2,
    OCT = 8,
    HEX = 16,
    UNKNOWN = -1
};
typedef struct Number {
    long long intNum;
    char *num;
    int sign;
    enum NumericalSystems nSys;
} Number;



char getOp(char *str);
enum NumericalSystems getSys(char *str);
int isValidNumber(char* str, enum NumericalSystems nSys);
long long myStrToInt(char *str, enum NumericalSystems nSys);
int charToInt(char ch);
Number getNum(char *str);
void decToHex(long long dec);
void decToOctal(long long dec);
void decToBinary(long long dec);
void printResult(long long result,enum NumericalSystems nSys);