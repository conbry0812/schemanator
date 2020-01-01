#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"




int main(int argc, char *argv[]) {
    int progStat=0;
    FILE *fp; //filePointer

    fp = fopen(argv[1],"r");

    //Confirm minimum reqs same number of start and end braces
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
        if(cType==0){
            startBraces=startBraces+1;
        }if(cType==1){
            endBraces=endBraces+1;
        }
    }
    if(startBraces!=endBraces){
        printf("Error not right amount of braces");
        return 1; //we exit the program if the minimal number of braces isn't present
    }
    //we rewind the file pointer to rescan the file
    rewind(fp);
    progStat=scannerStart(fp);

}


