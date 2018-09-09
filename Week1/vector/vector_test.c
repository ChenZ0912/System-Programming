/**
 * Vector Lab
 * CS 241 - Fall 2018
 */
#include <stdio.h>
#include "vector.h"
#include "assert.h"

void checkReserve(){
    vector * test = int_vector_create();
    vector_reserve(test, 1);
    assert(vector_capacity(test) == 8);
    vector_reserve(test, 8);
    assert(vector_capacity(test) == 8);
    vector_reserve(test, 9);
    assert(vector_capacity(test) == 16);
    vector_reserve(test, 10);
    assert(vector_capacity(test) == 16);
    vector_reserve(test, 17);
    assert(vector_capacity(test) == 32);
    vector_destroy(test);
}

void checkResize(){
    vector * test = int_vector_create();
    for (int i = 0; i < 9; i++){
        vector_push_back(test, &i);
        // printf("Size:%zu capacity:%zu\n", vector_size(test), vector_capacity(test));
    }
    
    vector_resize(test, 15);
    printf("size: %zu capacity: %zu\n", vector_size(test), vector_capacity(test));
    vector_resize(test, 17);
    
    vector_resize(test, 31);
    vector_resize(test, 100);
    
    for(size_t i = 0; i < vector_size(test); i++) {
        printf("index: %zu item:%d \n",i, *(int *)vector_get(test, i));
    }
    printf("Size:%zu capacity:%zu\n", vector_size(test), vector_capacity(test));
    vector_destroy(test);
    printf("Done...\n");
}

void checkSet(){
    vector * test = int_vector_create();
    for (int i = 0; i < 9; i++){
        vector_push_back(test, &i);
        // printf("Size:%zu capacity:%zu\n", vector_size(test), vector_capacity(test));
    }
    int random = 100;
    vector_set(test, 0, &random);
    for(size_t i = 0; i < vector_size(test); i++) {
        printf("item:%d \n", *(int *)vector_get(test, i));
    }
    vector_destroy(test);
    
}

void checkPop(){
    vector * test = int_vector_create();
    for (int i = 0; i < 10; i++){
        vector_push_back(test, &i);
        printf("Size:%zu capacity:%zu\n", vector_size(test), vector_capacity(test));
    }
    // for(size_t i = 0; i < vector_size(test); i++) {
    //   printf("item:%d \n", *(int *)vector_get(test, i));
    // }
    vector_resize(test, 31);
    printf("%zu\n", vector_size(test));
    for(size_t i = 0; i < vector_size(test); i++) {
        printf("item:%d \n", *(int *)vector_get(test, i));
    }
    printf("******************");
    printf("Size:%zu capacity:%zu", vector_size(test), vector_capacity(test));
    printf("******************\n");
    //
    for (size_t i = 0; vector_size(test) != 0; i++){
        vector_pop_back(test);
        printf("Size:%zu capacity:%zu\n", vector_size(test), vector_capacity(test));
    }
    for(size_t i = 0; i < vector_size(test); i++) {
        printf("item:%d \n", *(int *)vector_get(test, i));
    }
    vector_destroy(test);
    
}

void checkInsert(){
    vector * test = int_vector_create();
    for (int i = 0; i < 6; i++){
        vector_push_back(test, &i);
        printf("Size:%zu capacity:%zu content:%d\n", vector_size(test), vector_capacity(test), *(int *)vector_get(test, i));
    }
    int a1 = 100;
    vector_insert(test, 0, &a1);
    for(size_t i = 0; i < vector_size(test); i++) {
        printf("Size:%zu capacity:%zu content:%d position:%zu\n", vector_size(test), vector_capacity(test), *(int *)vector_get(test, i), i);
    }
    int a2 = 100;
    vector_insert(test, 6, &a2);
    for(size_t i = 0; i < vector_size(test); i++) {
        printf("Size:%zu capacity:%zu content:%d position:%zu\n", vector_size(test), vector_capacity(test), *(int *)vector_get(test, i), i);
    }
    
    int a3 = 30;
    vector_insert(test, 2, &a3);
    for(size_t i = 0; i < vector_size(test); i++) {
        printf("Size:%zu capacity:%zu content:%d position:%zu\n", vector_size(test), vector_capacity(test), *(int *)vector_get(test, i), i);
    }
    vector_destroy(test);
    
}

void checkErase(){
    vector * test = int_vector_create();
    for (size_t i = 0; i < 6; i++){
        vector_push_back(test, &i);
        printf("Size:%zu capacity:%zu content:%d position:%zu\n", vector_size(test), vector_capacity(test), *(int *)vector_get(test, i), i);
    }
    vector_erase(test,0);
    for(size_t i = 0; i < vector_size(test); i++) {
        printf("Size:%zu capacity:%zu content:%d position:%zu\n", vector_size(test), vector_capacity(test), *(int *)vector_get(test, i), i);
    }
    vector_erase(test,4);
    for(size_t i = 0; i < vector_size(test); i++) {
        printf("Size:%zu capacity:%zu content:%d position:%zu\n", vector_size(test), vector_capacity(test), *(int *)vector_get(test, i), i);
    }
    vector_destroy(test);
}
void resize_set_resizesmall_test(){
    vector* test = int_vector_create();
    //add 9 elements(size 9,capacity 16)
    for (size_t i = 0; i < 9; i++){
        vector_push_back(test, &i);
    }
    //resize the vector(size = 15, capacity = 16)
    vector_resize(test,15);
    //set test[0] to be 100
    int a = 100;
    vector_set(test, 0, &a);
    //set test[0] to be 100
    int b = 200;
    vector_set(test, 14, &b);
    //set test[0] to be 100
    int c = 300;
    vector_set(test, 7, &c);
    
    vector_resize(test,10);
    vector_resize(test,32);
    for(size_t i = 0; i < vector_size(test); i++) {
        printf("Size:%zu capacity:%zu content:%d position:%zu\n", vector_size(test), vector_capacity(test), *(int *)vector_get(test, i), i);
    }
    vector_destroy(test);
}



int main() {
    // Write your test cases here
//    checkReserve();
//    checkResize();
//    checkSet();
//    checkPop();
    //checkInsert();
//    checkErase();
//    resize_set_resizesmall_test();
    return 0;
}
