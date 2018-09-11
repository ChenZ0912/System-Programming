/**
 * Extreme Edge Cases Lab
 * CS 241 - Fall 2018
 */


#include <stdlib.h>
#include <ctype.h>
#include <string.h>
char **camel_caser(const char *input_str) {
    if (!input_str) {
        return NULL;
    }
    int count = 0;
    
    for (int i = 0; input_str[i] != '\0'; i++) {
        if (ispunct(input_str[i])) count++;
    }
    
    char** result = (char**)calloc(count + 1, sizeof(void*));
    
    char buffer[100];
    char string[100];
    int str_start_index = 0;
    int b_end_index = 0;
    int num_words = 0;
    count = 0;
    for (int i = 0; input_str[i] != '\0'; i++) {
        char curp_str = input_str[i];
        if ((isspace(curp_str) || ispunct(curp_str))) {
            if (b_end_index == 0) {
                continue;
            }
            if (num_words == 0) {
                buffer[0] = tolower(buffer[0]);
            }
            else {
                buffer[0] = toupper(buffer[0]);
            }
            num_words++;
            strncpy(string + str_start_index, buffer, b_end_index);
            str_start_index += b_end_index;
            if (ispunct(curp_str)) {
                string[str_start_index] = '\0';
                char* s = (char*)malloc(sizeof(char) * str_start_index);
                strncpy(s, string, str_start_index);
                result[count++] = s;
                str_start_index = 0;
                num_words = 0;
            }
            b_end_index = 0;
        }
        else {
            buffer[b_end_index] = input_str[i];
            b_end_index++;
        }
    }
    return result;
}

void destroy(char **result) {
    while(result) {
        free(*result);
        result++;
    }
    return;
}


