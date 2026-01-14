#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *values;
    size_t size;
} Vector;

void printVec(Vector *vec){
    printf("[ ");
    for(int i = 0; i < vec->size; i++){
        printf("%d, ", vec->values[i]);
    }    
    printf("]\n");
}

Vector addVec(Vector *vec1, Vector *vec2){
    int *data = malloc(sizeof(int) * vec1->size);
    if(vec1->size != vec2->size){
        exit(1);
    }
    for(int i = 0; i < vec1->size; i++){
        data[i] = vec1->values[i] + vec2->values[i];
    }
    Vector vec3 = {data, vec1->size};
    return vec3;
}

Vector initVec(int c, size_t size){
    int *data = malloc(sizeof(int) *  size);
    for(size_t i = 0; i < size; i++){
        data[i] = c;
    } 
    Vector vec = {data, size};
    return vec;
}

int main() {
    Vector v1 = initVec(2, 5);
    Vector v2 = initVec(1,5);
    Vector v3 = addVec(&v1, &v2);
    printVec(&v3);
    return 0;
}

