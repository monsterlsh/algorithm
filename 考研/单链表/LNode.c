#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node * next;
}Node, * LinkList;
bool getElem_L(LinkList L,int i, int & e);
bool ListInsert_L(LinkList L,int i, int & e);
void InitList(LinkList & L,int n);
int main(void){
    LinkList la,lb,lc;
    InitList(la,8);
    int elem = 0;
    if(getElem_L(la,4,elem)) printf("%d\n",elem);
    return 0;

}
void InitList(LinkList & L,int n){
    LinkList p ;//= (LinkList)malloc(sizeof(Node));
    for(int i=0;i<n;i++){
        scanf("%d",&p->data);
        p->next =NULL;
        L->next = p;
        p = p->next;
    }
    free(p);
}
bool getElem_L(LinkList L,int i, int & e){
    Node * p = L->next; int j =1;
    while(p && j<i){
        p = p->next; j++;
    }
    if(!p || j > i) return false;
    e = p->data;
    return true;
}
bool ListInsert_L(LinkList & L,int i, int e){
    LinkList p = L->next; int j =0;
    while(p && j<i){
        p = p->next; j++;
    }
    if(!p || j > i) return false;
    LinkList x = (LinkList)malloc(sizeof(Node));
    x->next = p->next;
    p->next = x;
    x->data =e;
    return true;
}
