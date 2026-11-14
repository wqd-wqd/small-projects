#ifndef ARRAY_H_
#define ARRAY_H_

typedef struct{
    int *array;
    int size;
}Array;

Array array_create(int init_size);
int *array_at(int num,Array *a);
void array_free(Array *a);
void array_inflate(int more_size,Array *a);
int array_size(Array *a,int num);

#endif