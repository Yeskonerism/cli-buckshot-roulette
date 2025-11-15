//
// Created by yeskonerism on 15/11/2025.
//

#ifndef BUCKSHOT_ROULETTE_STRING_H
#define BUCKSHOT_ROULETTE_STRING_H

#include <stdlib.h>
#include <string.h>

// custom string type
typedef char* string;

// initialise string
string str(const char* value) {
    char* mem = malloc(strlen(value) + 1);
    if(mem == NULL) return NULL;

    strcpy(mem, value);

    return mem;
}

// initialise string
string str_buff(const char* value, int bufferSize) {
    char* mem = malloc(bufferSize);
    if(mem == NULL) return NULL;

    strcpy(mem, value);

    return mem;
}

// free string vars from memory
void str_free(char* str) {
    free(str);
}

// copy one string to a separate destination
void str_copy(string source, string* dest) {
    *dest = str(source);
}

// return length of given string
int str_length(const char* value) {
    int length = 0;

    for(int i = 0; value[i] != '\0'; i++) {
        length++;
    }

    return length;
}

// compare 2 strings together and return 1 if they are the same
int str_equals(const char* str1, const char* str2) {
    if(str_length(str1) != str_length(str2))
        return 0;

    for(int i = 0; str1[i] != '\0'; i++) {
        if(str1[i] != str2[i])
            return 0;
    }

    return 1;
}

#endif //BUCKSHOT_ROULETTE_STRING_H