#include<stdio.h>

typedef struct{
    int data[100];
    int top;
}Stack;

void push(Stack* s,int num);
int pop(Stack *s);
int top(Stack* s);
int isEmpty(Stack *s);

int main(){
    int num;
    Stack stack;
    stack.top=0;
    while(scanf("%d",&num)==1&&num!=-1){
        if(stack.top>=100)break;
        push(&stack,num);
    }
    int count;
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        int x=pop(&stack);
        if(x==-1){printf("空栈");break;}
        printf("%d\n",x);
    }
    return 0;
}

void push(Stack* s,int num){
    if(s->top>=100){printf("栈满了\n");return;}
    s->data[(s->top)++]=num;
}

int pop(Stack *s){
    if(isEmpty(s))return -1;
    else s->top-=1;
    return s->data[s->top];
}

int top(Stack* s){
    if(isEmpty(s)){printf("空栈\n");return -1;}
    return s->data[s->top-1];
}

int isEmpty(Stack *s){
    return s->top==0; 
}