/**
* Vector Lab
* CS 241 - Fall 2018
*/

#include "sstring.h"
#include "vector.h"

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <assert.h>
#include <string.h>

struct sstring {
    int length;
    char* string;
};

sstring *cstr_to_sstring(char *input) {
    // your code goes here
    int len = strlen(input);
    sstring* sst = (sstring*)malloc(sizeof(sstring));
    char* st = (char*)calloc(len + 1, sizeof(char));
    sst->length = len;
    strcpy(st, input);
    sst->string = st;
    return sst;
}

char *sstring_to_cstr(sstring *input) {
    // your code goes here
    char* res = (char*)calloc(input->length + 1, sizeof(char));
    strcpy(res, input->string);
    return res;
}

int sstring_append(sstring *this, sstring *addition) {
    // your code goes here
    int new_len = this->length + addition->length;
    this->string = (char*)realloc(this->string, new_len);
    for (int i = this->length; i < new_len; i++) {
        this->string[i] = addition->string[i - this->length];
    }
    this->string[new_len] = '\0';
    this->length = new_len;
    return new_len;
}

vector *sstring_split(sstring *this, char delimiter) {
    // your code goes here
    vector* vec = string_vector_create();
    char* cstr = this->string;
    int start = -1;
    size_t p;
    for (p = 0; ; p++) {
        if (cstr[p] == delimiter || cstr[p] == '\0') {
            char* st = (char*)calloc(p - start + 1, sizeof(char));
            strncpy(st, &cstr[start], p - start);
            vector_push_back(vec, st);
            if (cstr[p] == '\0') {
                break;
            }
            start = -1;
        }
        else {
            if (start == -1) {
                start = p;
            }
        }
    }
    
    return vec;
}

int sstring_substitute(sstring *this, size_t offset, char *target,
                       char *substitution) {
    // your code goes here
    int new_len = this->length - strlen(target) + strlen(substitution);
    char* new_str = (char*)malloc(sizeof(char) * (new_len));
    bool found = false;
    int len_sub = strlen(substitution);
    int len_tat = strlen(target);
    
    for (int i = offset; i < this->length; i++) {
        if (!found && this->string[i] == target[0]) {
            int t = 0;
            while(t < len_tat && this->string[i + t] == target[t]) {
                t++;
            }
            if (t == len_tat) {
                memcpy(new_str + i, substitution, len_sub);
                memcpy(new_str + i + len_sub , this->string + i + len_tat, this->length - t - i);
                new_str[new_len] = '\0';
                printf("%s\n", new_str);
                free(this->string);
                this->string = new_str;
                this->length = new_len;
                return 0;
            }
            else {
                new_str[i] = this->string[i];
            }
        }
        else {
            new_str[i] = this->string[i];
        }
    }
    return -1;
}

char *sstring_slice(sstring *this, int start, int end) {
    // your code goes here
    char* res = (char*)malloc(sizeof(char) * (end - start + 1));
    strncpy(res, this->string + start, end - start);
    return res;
}

void sstring_destroy(sstring *this) {
    // your code goes here
    free(this->string);
    free(this);
}
