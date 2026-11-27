#include<stdio.h>

int heap[100005];
int sz=0;

void push(int x){
    int i=sz;
    heap[sz++]=x;
    while(i>0){
        int p=(i-1)/2;
        if(heap[i]>=heap[p])break;
        int t=heap[i];heap[i]=heap[p];heap[p]=t;
        i=p;
    }
}

int top(){
    return heap[0];
}

void pop(){
    heap[0]=heap[--sz];
    int i=0;
    while(1){
        int l=2*i+1,r=2*i+2;
        int s=i;
        if(l<sz&&heap[l]<heap[s])s=l;
        if(r<sz&&heap[r]<heap[s])s=r;
        if(s==i)break;
        int t = heap[i]; heap[i] = heap[s]; heap[s] = t;
        i=s;
    }
}

int main(){
    int num,n;
    while(scanf("%d",&num)==1&&num!=-1)push(num);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        if(sz>0){
            printf("%d",top());
            pop();
        }
        else break;
    }
    return 0;
}