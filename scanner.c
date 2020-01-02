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
    FILE *fileCopy;
    fileCopy = fp; //make a copy of the original file pointer so it's not modified.
    char c; //char to hold character from pointer
    int cType = 0;
    int counter = 0;
    int tokOrLex = 1;
    int isNum = 0;

    char *string;


    while ((intC = fgetc(fp)) != EOF) {
        c = (char) intC;
        cType = reservedCharType(c);
        if (cType == 4) {
            //Token is " and so is lexem
            writeCharToFile(c);
            writeCharToFile('\t');
            writeCharToFile(c);
            writeCharToFile('\n');
            tokOrLex = scanString(fileCopy, tokOrLex); //this determines if we're printing a token or Lexem
            writeCharToFile(c);
            writeCharToFile('\t');
            writeCharToFile(c);
            writeCharToFile('\n');
            counter++;
            //we're in a string and need to take some string related action
        } else if(cType==5){
            //rewind(fileCopy);
            writeCharToFile(c);
            writeCharToFile('\t');
            writeCharToFile(c);
            writeCharToFile('\n');
            tokOrLex = scanArry(fileCopy);
            writeCharToFile(c);
            writeCharToFile('\t');
            writeCharToFile(c);
            writeCharToFile('\n');
        }
        else if(cType==100){
            isNum = isInt(c);
            if(isNum==1){
                tokOrLex = scanNum(fileCopy);
            }
        }
        else {
            writeCharToFile(c);
            writeCharToFile('\t');
            writeCharToFile(c);
            writeCharToFile('\n');
        }
    }
    return 0; //need new return number for error/debugging
}

int scanArry(FILE *fp){
    int intC;
    char c;

    writeCharToFile('V');
    writeCharToFile('A');
    writeCharToFile('L');
    writeCharToFile('U');
    writeCharToFile('E');
    writeCharToFile('\t');


    while ((intC = fgetc(fp)) != ']') {
        if(intC !='[') {
            c = (char) intC;
            writeCharToFile(c);
        }
    }
    writeCharToFile('\n');

    return 1;

}

int isInt(char num){
    for(int i=0;i<10;i++){
        if(num==nums[i]);
        return 1;
    }
    return 0;

}

int scanNum(FILE *fp){
    int intC;
    char c;
    int retVal=0;

    fseek(fp,-1L,SEEK_CUR);
    writeCharToFile('V');
    writeCharToFile('A');
    writeCharToFile('L');
    writeCharToFile('U');
    writeCharToFile('E');
    writeCharToFile('\t');

    while ((intC = fgetc(fp)) != ',') {
        if(intC !=':') {
            c = (char) intC;
            writeCharToFile(c);
        }
    }
    writeCharToFile('\n');
    return 1;
}

int scanString(FILE *fp, int first){
    int intC;
    char c;
    int retVal=0;

    if(first == 1){
        writeCharToFile('K');
        writeCharToFile('E');
        writeCharToFile('Y');
        writeCharToFile('\t');
    }else{
        writeCharToFile('V');
        writeCharToFile('A');
        writeCharToFile('L');
        writeCharToFile('U');
        writeCharToFile('E');
        writeCharToFile('\t');
        retVal=1;
    }
    while ((intC = fgetc(fp)) != '"') {
        if(intC !='"') {
            c = (char) intC;
            writeCharToFile(c);
        }
    }
    writeCharToFile('\n');
    return retVal;
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

