#include<stdio.h>
#include<stdlib.h>
#include"array.h"

const int block=20;

Array array_create(int init_size){
    Array a;
    a.size=init_size;
    a.array=(int*)malloc(sizeof(int)*(a.size));
    return a;
}

void array_free(Array *a){
    free(a->array);
    a->size=0;
    a->array=NULL;
}

int *array_at(int num,Array *a){
    if(num>=(a->size)){
        array_inflate((num/block+1)*block-a->size,a);
    }
    return &(a->array[num]);
}

int array_size(Array *a,int num){
    return a->array[num];
}

void array_inflate(int more_size,Array *a){
    int *p=(int*)malloc(sizeof(int)*(more_size+a->size));
    for(int i=0;i<a->size;i++){
        p[i]=a->array[i];
    }
    free(a->array);
    a->size+=more_size;
    a->array=p;
}


int main(){
    Array a=array_create(100);
    int count=0;
    int num=0;
    while(scanf("%d",&num)==1&&num!=-1){
        *array_at(count++,&a)=num;
    }
    //array_free(&a);
    return 0;
}