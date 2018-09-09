/**
 * Vector Lab
 * CS 241 - Fall 2018
 */

#include "sstring.h"
#include <stdio.h>
#include "vector.h"
#include <assert.h>
#include <string.h>

void checkToSstring() {
    char * a = "";
    sstring * a_sst = cstr_to_sstring(a);
    char* ret = sstring_to_cstr(a_sst);
    assert(strcmp(ret, "") == 0);
    // char * b = "abc";
    // sstring * b_sst = cstr_to_sstring(b);
    // assert(strcmp(sstring_to_cstr(b_sst), "abc") == 0);
    // char * c = "\0";
    // sstring * c_sst = cstr_to_sstring(c);
    // assert(strcmp(sstring_to_cstr(c_sst), "\0") == 0);
    sstring_destroy(a_sst);
    free(ret);
    // sstring_destroy(b_sst);
    // sstring_destroy(c_sst);
    printf("checkToSstring Done.\n");
}

void checkAppend(){
    char * a = "";
    char * a1 = "abc";
    char * a2 = "def";
    char * a3 = "\n";
    sstring* result = cstr_to_sstring(a);
    sstring* s1 = cstr_to_sstring(a1);
    sstring* s2 = cstr_to_sstring(a2);
    sstring* s3 = cstr_to_sstring(a3);
    
    assert(sstring_append(result, s1) == 3);
    assert(sstring_append(result, s2) == 6);
    assert(sstring_append(result, s3) == 7);
    sstring_destroy(result);
    sstring_destroy(s1);
    sstring_destroy(s2);
    sstring_destroy(s3);
    printf("checkAppend Done.\n");
}

void checkSplit(){
    printf("********************\n");
    char * a = "Hello world ";
    sstring * a_sst = cstr_to_sstring(a);
    printf("********************\n");
    vector* result1 = sstring_split(a_sst, ' ');
    for(size_t i = 0; i < vector_size(result1); i++) {
        printf("%s\n", vector_get(result1, i));
    }
    sstring_destroy(a_sst);
    vector_destroy(result1);
    printf("********************\n");
    char * b = "Hello world ";
    sstring * b_sst = cstr_to_sstring(b);
    vector* result2 = sstring_split(b_sst, 'Z');
    for(size_t i = 0; i < vector_size(result2); i++) {
        printf("%s\n", vector_get(result2, i));
    }
    sstring_destroy(b_sst);
    vector_destroy(result2);
    printf("********************\n");
    
    char * c = "Hello world ";
    sstring * c_sst = cstr_to_sstring(c);
    vector* result3 = sstring_split(c_sst, '\0');
    for(size_t i = 0; i < vector_size(result3); i++) {
        printf("%s\n", vector_get(result3, i));
    }
    sstring_destroy(c_sst);
    vector_destroy(result3);
    printf("********************\n");
}

void checkSub(){
    // char * c = "Hello world";
    // char *target = "d\0";
    // char *sub = "dsvsdv\0";
    // sstring * c_sst = cstr_to_sstring(c);
    // sstring_substitute(c_sst, 0, target, sub);
    // printf("%s\n", sstring_to_cstr(c_sst));
    
    char * c = "{}!";
    char *target = "{}";
    // char *sub = "friend";
    sstring * c_sst = cstr_to_sstring(c);
    sstring_substitute(c_sst, 0, target, "friend");
    char* result = sstring_to_cstr(c_sst);
    sstring_destroy(c_sst);
    free(result);
    
    // char * c = "ABCXXXDEF";
    // char *target = "XXX";
    // // char *sub = "friend";
    // sstring * c_sst = cstr_to_sstring(c);
    // sstring_substitute(c_sst, 0, target, " ");
    // char* result = sstring_to_cstr(c_sst);
    // printf("%s\n", result);
    // free(result);
    // sstring_destroy(c_sst);
}

int main() {
    //TODO create some tests
    checkToSstring();
    checkAppend();
    checkSplit();
    checkSub();
}
