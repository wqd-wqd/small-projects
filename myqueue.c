#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    struct _node *next;
    int value;
}Node;

typedef struct {
    Node *head;
    Node *tail;
}Queue;

int isEmpty(Queue *p);
void enqueue(Queue *pqueue,int num);
int dequeue(Queue *pqueue);
int front(Queue *pqueue);

int main(){
    int num;
    Queue queue;
    queue.head=NULL;
    queue.tail=NULL;
    while(scanf("%d",&num)==1&&num!=-1)enqueue(&queue,num);
    scanf("%d",&num);   //要出队几个
    for(int i=0;i<num;i++){
        int x=dequeue(&queue);
        if(x==-1)printf("队已空\n");
        else printf("%d退队\n",x);
    }
    int x=front(&queue);
    if(x==-1)printf("队是空的\n");
    else printf("队首是%d\n",x);
    Node *p,*q;
    for(q=NULL,p=queue.head;p;p=q){
        q=p->next;
        free(p);
    }
    return 0;
}

void enqueue(Queue *pqueue,int num){
    Node *p=malloc(sizeof(Node));
    p->value=num;
    p->next=NULL;
    if(isEmpty(pqueue)){
        pqueue->head=p;
        pqueue->tail=p;
    }else{
        pqueue->tail->next=p;
        pqueue->tail=p;
    } 
}

int isEmpty(Queue *p){
    return p->head==NULL;
}

int dequeue(Queue *pqueue){
    Node *p;
    if(isEmpty(pqueue))return -1;
    else {
        int num=pqueue->head->value;
        p=pqueue->head;
        pqueue->head=p->next;
        if(pqueue->head==NULL)pqueue->tail=NULL;
        free(p);
        return num;
    }
}

int front(Queue *pqueue){
    if(isEmpty(pqueue))return -1;
    else return pqueue->head->value;
}