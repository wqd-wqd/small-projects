#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
}Node;

typedef struct{
    Node *head;
}List;

void add(List *plist,int num);
int isEmpty(List *plist);
int delete(List *plist,int num);
void ifree(List *plist);
void print(List *plist);

int main(){
    int num;
    List list;
    list.head=NULL;
    while(scanf("%d",&num)==1&&num!=-1)add(&list,num);
    scanf("%d",&num);//删哪个
    int x=delete(&list,num);
    if(x==-1)printf("空的\n");
    else if(x==0) printf("没找到\n");
    else printf("找到并删除\n");
    print(&list);
    ifree(&list);
    return 0;
}

void add(List *plist,int num){
    Node *p=malloc(sizeof(Node));
    p->next=NULL;
    p->value=num;
    Node *q;
    if(isEmpty(plist)){
        plist->head=p;
    }else{
        for(q=plist->head;q->next;q=q->next);
        q->next=p;
    }
}

int isEmpty(List *plist){
    return plist->head==NULL;
}

int delete(List *plist,int num){
    if(isEmpty(plist))return -1;
    int found=0;
    Node *p,*q;
    for(q=NULL,p=plist->head;p;q=p,p=p->next){
        if(p->value==num){
            found=1;
            if(q){
            q->next=p->next;
            }else{
                plist->head=p->next;
            }
            free(p);
            break;
        }
    }
    return found;
}

void ifree(List *plist){
    Node *p,*q;
    for(q=NULL,p=plist->head;p;p=q){
        q=p->next;
        free(p);
    }
}

void print(List *plist){
    Node *p;
    for(p=plist->head;p;p=p->next)printf("%d\t",p->value);
}