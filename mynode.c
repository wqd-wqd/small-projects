#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
}Node;

typedef struct _list{
    Node *head;
}List;

void print(List *plist);
void add(int num,List *plist);

int main(){
    int num;
    List list;
    list.head=NULL;
    while(scanf("%d",&num)==1&&num!=-1)add(num,&list);
    int isFound=0;
    Node *p;
    Node *q;
    scanf("%d",&num);
    for(q=NULL,p=list.head;p;q=p,p=p->next){
        if(p->value==num){
            isFound=1;
            if(q) q->next=p->next;
            else list.head=p->next;
            free(p);
            break;
        }
    }
    if(isFound==1)printf("find");
    else printf("no find");
    print(&list);
    for(p=list.head;p;p=q){
    q=p->next;
    free(p);
}
    return 0;
}

void add(int num,List *plist){
    Node *p=malloc(sizeof(Node));
    Node *q;
    p->value=num;
    p->next=NULL;
    if(plist->head){
        for(q=plist->head;q->next;q=q->next);
        q->next=p;
    }else plist->head=p;
}

void print(List *plist){
    Node *p;
    for(p=plist->head;p;p=p->next){
        printf("%d\t",p->value);
    }
    printf("\n");
}