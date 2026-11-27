#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
}Node;

Node *newNode(int v){
    Node *p=(Node*)malloc(sizeof(Node));
    p->value=v;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void levelorder(Node *root){
    if(root==NULL)return ;
    Node *q[100005];
    int head=0,tail=0;
    q[tail++]=root;
    while(head<tail){
        Node *cur=q[head++];
        printf("%d ",cur->value);
        if(cur->left)q[tail++]=cur->left;
        if(cur->right)q[tail++]=cur->right;
    }
}

void freetree(Node *root){
    if(root==NULL)return ;
    freetree(root->left);
    freetree(root->right);
    free(root);
}

int main(){
    Node *n1 = newNode(1);
    Node *n2 = newNode(2);
    Node *n3 = newNode(3);
    Node *n4 = newNode(4);
    Node *n5 = newNode(5);
    Node *n6 = newNode(6);
    n1->left = n2;  n1->right = n3;
    n2->left = n4;  n2->right = n5;
    n3->right = n6;
    printf("层次: ");
    levelorder(n1);  
    printf("\n");

    freetree(n1);
    return 0;
}