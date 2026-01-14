#include <stdio.h>
#include <stdlib.h>

/*
    Vector object type definition
 */

typedef struct {
    int *data;
    size_t size;
} Vector;

/*
    Function to get console output of a vector
 */

void printVec(Vector *vec){
    printf("[ ");
    for(int i = 0; i < vec->size; i++){
        printf("%d, ", vec->data[i]);
    }    
    printf("]\n");
}

/*
    Function to add together two vectors. Returns the resultant vector.
 */

Vector addVec(Vector *vec1, Vector *vec2){
    int *data = malloc(sizeof(int) * vec1->size);
    if(vec1->size != vec2->size){
        exit(1);
    }
    for(int i = 0; i < vec1->size; i++){
        data[i] = vec1->data[i] + vec2->data[i];
    }
    Vector vec3 = {data, vec1->size};
    return vec3;
}

/*
    Function to initialise a vector of requisite element and size.
 */

Vector initVec(int c, size_t size){
    int *data = malloc(sizeof(int) *  size);
    for(size_t i = 0; i < size; i++){
        data[i] = c;
    } 
    Vector vec = {data, size};
    return vec;
}

/*
    Function to multiply a vector by a scalar. The multiplication is in place.
 */

void scalarMul(int c, Vector *vec){
    // multiplies each element of the vector in situ.
    for(size_t i = 0; i < vec->size; i++){
        vec->data[i] *= c;
    }
}

/*
    Function to multiply two vectors.
 */

int vectorMul(Vector *vec1, Vector *vec2){
    int res = 0;
    if(vec1->size != vec2->size){
        exit(1);
    }
    for(size_t i = 0; i < vec1->size; i++){
        res += vec1->data[i] * vec2->data[i];    
    }
    return res;
}

/*
    Example usage
 */

int main() {
    Vector v1 = initVec(2, 5);
    Vector v2 = initVec(1,5);
    Vector v3 = addVec(&v1, &v2);

    //scalarMul(2, &v2);
    printVec(&v2);

    printVec(&v3);

    int a = vectorMul(&v1, &v2);
    printf("The vector product is %d\n", a);
    return 0;
}