#include<stdio.h>
#include<stdlib.h>

typedef struct _node{
    int value;
    struct _node *right;
    struct _node *left;
}Node;

Node *insert(Node *root,int num){
    if(root==NULL){
        Node *p=(Node*)malloc(sizeof(Node));
        p->value=num;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    if(root->value>num){
        root->left=insert(root->left,num);
    }else{
        root->right=insert(root->right,num);
    }
    return root;
}

int find(Node *root,int x){
    if(root==NULL)return 0;
    if(x==root->value)return 1;
    if(x<root->value){
        return find(root->left,x);
    }else{
        return find(root->right,x);
    }
}

void freetree(Node *root){
    if(root==NULL) return ;
    freetree(root->right);
    freetree(root->left);
    free(root);
}

void preorder(Node *root){
    if(root==NULL)return ;
    printf("%d ",root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root){
    if(root==NULL)return ;
    inorder(root->left);
    printf("%d ",root->value);
    inorder(root->right);
}

void postorder(Node *root){
    if(root==NULL)return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->value);
}

int main(){
    int num,x;
    Node *root=NULL;
    while(scanf("%d",&num)==1&&num!=-1)root=insert(root,num);
    scanf("%d",&x);//查找的数
    int m=find(root,x);
    if(m)printf("找到了\n");
    else printf("没找到\n");
    printf("前序：");
    preorder(root);
    printf("\n中序:");
    inorder(root);
    printf("\n后序:");
    postorder(root);
    freetree(root);
    return 0;
}