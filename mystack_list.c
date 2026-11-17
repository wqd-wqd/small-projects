#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
}Node;

typedef struct {
    Node *head;
}Stack;

int isEmpty(const Stack *phead);
int top(const Stack *phead);
int pop(Stack *phead);
void push(Stack* phead,int num);

int main(){
    Stack stack;
    stack.head=NULL;
    int num;
    while(scanf("%d",&num)==1&&num!=-1)push(&stack,num);
    int count;
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        if(isEmpty(&stack)){printf("栈已空\n");break;}
        int a=pop(&stack);
        printf("%d\n",a);
    }
    int x=top(&stack);
    if(x==-1)printf("空栈\n");
    else printf("top is %d\n",x);
    Node *p,*q;
    for(p=stack.head;p;p=q){
        q=p->next;
        free(p);
    }
    return 0;
}

void push(Stack* phead,int num){
    Node *p=malloc(sizeof(Node));
    p->value=num;
    p->next=phead->head;
    phead->head=p;
}

int pop(Stack *phead){
    if(isEmpty(phead)){printf("空栈\n");return -1;}
    Node *p;
    p=phead->head;
    int x=p->value;
    if(p->next==NULL)phead->head=NULL;
    phead->head=p->next;
    free(p);
    return x;
}

int top(const Stack *phead){
    if(isEmpty(phead))return -1;
    Node *p=phead->head;
    return p->value;
}

int isEmpty(const Stack *phead){
    return phead->head==NULL;
}