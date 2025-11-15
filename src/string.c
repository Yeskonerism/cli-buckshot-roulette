//
// Created by yeskonerism on 15/11/2025.
//

#include "include/string.h"

string str (const char* value) {
    char* mem = malloc(strlen(value) + 1);
    if(mem == NULL) return NULL;

    strcpy(mem, value);

    return mem;
}

string str_buff(const char* value, int bufferSize) {
    char* mem = malloc(bufferSize);
    if(mem == NULL) return NULL;

    strcpy(mem, value);

    return mem;
}

void str_free(char* str) {
    free(str);
}

void str_copy(string source, string* dest) {
    *dest = str(source);
}

int str_length(const char* value) {
    int length = 0;

    for(int i = 0; value[i] != '\0'; i++) {
        length++;
    }

    return length;
}

int str_equals(const char* str1, const char* str2) {
    if(str_length(str1) != str_length(str2))
        return 0;

    for(int i = 0; str1[i] != '\0'; i++) {
        if(str1[i] != str2[i])
            return 0;
    }

    return 1;
}

string str_input(string prompt) {
    string input = str_buff("",99); // create a buffer for the player name

    printf("%s: ", prompt);
    scanf("%99s", input); // limit scanf to 99 characters to prevent buffer overflow

    return input;
}

string str_input_buff(string prompt, int bufferSize) {
    char format[20];

    sprintf(format, "%%%ds", bufferSize - 1);

    string input = str_buff("",bufferSize); // create a buffer for the player name

    printf("%s: ", prompt);
    scanf(format, input); // limit scanf to 99 characters to prevent buffer overflow

    return input;
}