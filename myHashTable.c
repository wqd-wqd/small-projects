#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
}Node;

typedef struct{
    Node *bucket[10007];
}HashTable;

int hash(int x){     //进哪个桶里
    return ((x%10007)+10007)%10007;
}

void init(HashTable *t){
    for(int i = 0; i < 10007; i++) t->bucket[i] = NULL;
}

void insert(HashTable *t,int x){     //装桶
    Node *p=(Node*)malloc(sizeof(Node));
    p->value=x;
    int h=hash(x);
    p->next=t->bucket[h];
    t->bucket[h]=p;
}

int find(HashTable *t,int x){
    int h=hash(x);
    for(Node *p=t->bucket[h];p;p=p->next){
        if(p->value==x)return 1;
    }
    return 0;
}

void destroy(HashTable *t){
    Node *q,*p;
    for(int i=0;i<10007;i++){
        for(q=NULL,p=t->bucket[i];p;p=q){
            q=p->next;
            free(p);
        }
        t->bucket[i]=NULL;
    }
}

int main(){
    HashTable t;
    init(&t);

    insert(&t, 1);
    insert(&t, 10008);   
    insert(&t, 5);
    insert(&t, 20015);   

    printf("%d\n", find(&t, 1));    
    printf("%d\n", find(&t, 10008));  
    printf("%d\n", find(&t, 5));      
    printf("%d\n", find(&t, 20015));  
    printf("%d\n", find(&t, 7)); 

    destroy(&t);
    return 0;
}