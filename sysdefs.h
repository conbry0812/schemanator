//
// Created by jrinder on 12/31/19.
//

#ifndef JSONPARSER_SYSDEFS_H
#define JSONPARSER_SYSDEFS_H

char gramChars[5] = {'{','}',':',',','"'}; //These are characters we won't pull
int maxGramChars=5;
void stringBuilder(char c, char **string, int size);

#endif //JSONPARSER_SYSDEFS_H
