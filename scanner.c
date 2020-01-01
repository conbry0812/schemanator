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
    char prevC;
    int cType = 0;
    int drop = 0; //boolean drop or keep
    int size = 0; //size of string to be build
    int counter = 1;
    int split;
    int startBraces = 0;
    int endBraces = 0;
    int writeNewLine=0;
    int tokeType = 0;
    int writeToke = 0;


    while ((intC = fgetc(fp)) != EOF) {
        c = (char) intC;
        cType = reservedCharType(c);
        if(cType!=100){
            if(cType==2){
                tokeType=1;
                writeToke=1;
            }else{
                tokeType=2;
                writeToke=1;
            }
            if(writeNewLine==1){
                writeCharToFile('\n');
                writeNewLine=0;
            }
            writeCharToFile(c);
            writeCharToFile('\t');
            writeCharToFile(c);
            writeCharToFile('\n');

        }else{
            if(tokeType==1 && writeToke==1) {
                writeCharToFile('V');
                writeCharToFile('A');
                writeCharToFile('L');
                writeCharToFile('U');
                writeCharToFile('E');
                writeCharToFile('\t');
                tokeType=0;
                writeToke=0;
            }
            if(tokeType==2 && writeToke==1) {
                writeCharToFile('K');
                writeCharToFile('E');
                writeCharToFile('Y');
                writeCharToFile('\t');
                tokeType=0;
                writeToke=0;
            }
            writeNewLine=1;
            writeCharToFile(c);
        }
    }
    return 0; //need new return number for error/debugging
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

