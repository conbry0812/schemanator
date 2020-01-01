//
// Created by jrinder on 1/1/20.
//

#ifndef SCHEMANATOR_UNIVERSALFUNCTIONS_H
#define SCHEMANATOR_UNIVERSALFUNCTIONS_H

#include <bits/types/FILE.h>
#include <stdio.h>

void writeCharToFile(char c){
    FILE * flPntr;
    flPntr=fopen("scan.scn","a");
    fputc(c, flPntr);
    fclose(flPntr);

}

char *stringBuilder(char c, int size, char *Strng)
{
    int arryPosit=size-1;
    char sub[700];
    Strng[arryPosit]=c;

    return Strng;
}

#endif //SCHEMANATOR_UNIVERSALFUNCTIONS_H
