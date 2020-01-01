//
// Created by jrinder on 1/1/20.
//

#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"
#include "sysdefs.h"
#include "universalFunctions.h"

int scannerStart(FILE *fp) {
    int intC; //int for holing pointer
    char c; //char to hold character from pointer
    int cType = 0;
    int drop = 0; //boolean drop or keep
    int size = 0; //size of string to be build
    int split;
    int startBraces = 0;
    int endBraces = 0;


    while ((intC = fgetc(fp)) != EOF) {
        c = (char) intC;
        cType = reservedCharType(c);
        if(cType!=100){
            writeCharToFile(c);
            writeCharToFile('\t');
            writeCharToFile(c);
            writeCharToFile('\n');
        }
    }

}


int reservedCharType(char c){
    int i = 0;
    for(i=0;i<maxGramChars;i++){
        if(c == gramChars[i]){
            return i;
        }
    }
    return 100;
}

void stringBuilder(char c, char **string, int size){
    *string = (char *) malloc(size * sizeof(char));
}