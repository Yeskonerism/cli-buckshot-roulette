//
// Created by yeskonerism on 15/11/2025.
//

#ifndef BUCKSHOT_ROULETTE_STRING_H
#define BUCKSHOT_ROULETTE_STRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// custom string type
typedef const char* string;

// initialise string
string str(const char* value);
string str_buff(const char* value, int bufferSize);

// free string vars from memory
void str_free(char* str);

// copy one string to a separate destination
void str_copy(string source, string* dest);

// return length of given string
int str_length(const char* value);

// compare 2 strings together and return 1 if they are the same
int str_equals(const char* str1, const char* str2);

// get input from user and return as string
string str_input(string prompt);
string str_input_buff(string prompt, int bufferSize);

#endif //BUCKSHOT_ROULETTE_STRING_H