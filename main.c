#include <stdio.h>
#include "sysdefs.h"
#include <stdlib.h>

void stringBuilder(char c, char **string, int size){
    *string = (char *) malloc(size * sizeof(char));

}


int dropChar(char c){
    int i=0; //loop counter
    int size=0; //size of String to be built
    //cout
    for(i=0;i<maxGramChars;i++){
        if(c == gramChars[i]){
            return 1;
        }
    }
    return 0;
}

int isCharDelim(char c){
    if(c==':'){
        return 1;
    }
    return 0;
}

int incrementSize(int i, int size){
    if(i==0){
        return size + 1;
    }
    return size;
}

void writeToLines2(char *txt, char *txt2){
    FILE * flPntr;
    flPntr = fopen("outParser.txt","a");
    char* txt1;
    //txt1 = strcat(txt,txt2);
    fprintf(flPntr, "%s",txt);
    fclose(flPntr);
}

int obtainLargestString(FILE *file){
    int chr;
    char c;
    int drop=0;
    int size=0;
    int sizeAr[2];
    int split;

    while((chr=fgetc(file))!=EOF){
        c = (char) chr;
        drop = dropChar(c);
        split = isCharDelim(c);
        if(split==0) {
            size = incrementSize(drop, size);
        }else{
            size = 0;
            //write to file
        }
    }

}

int main(int argc, char *argv[]) {
    int intC; //int for holing pointer
    char c; //char to hold character from pointer
    int drop=0; //boolean drop or keep
    int size=0; //size of string to be build
    int split;

    FILE *fp; //filePointer

    fp = fopen(argv[1],"r");

    while((intC=fgetc(fp))!=EOF){
        c = (char) intC;
        drop = dropChar(c);
        split = isCharDelim(c);
        if(split==0) {
            size = incrementSize(drop, size);
        }else{
            size = 0;
            //write to file
        }
    }
}


