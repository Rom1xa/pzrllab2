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
    char num[128];
    int sign;
    enum NumericalSystems nSys;
} Number;



char getOp(char *str);
enum NumericalSystems getSys(char *num);
int isValidNumber(char* str, enum NumericalSystems nSys);