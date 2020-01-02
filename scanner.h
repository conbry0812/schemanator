//
// Created by jrinder on 1/1/20.
//

#ifndef SCHEMANATOR_SCANNER_H
#define SCHEMANATOR_SCANNER_H

int scannerStart(FILE *fp);

int reservedCharType(char c);
int scanString(FILE *fp, int first);
int scanArry(FILE *fp);
int isInt(char num);
int scanNum(FILE *fp);

#endif //SCHEMANATOR_SCANNER_H
