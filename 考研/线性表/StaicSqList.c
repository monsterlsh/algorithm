#include<stdio.h>
#define MaxSize 50
typedef struct{
    int data[MaxSize];
    int length;
}SqList;
bool Reserve_Sql(SqList & l);
void temp(int *m , int *n);
void print_Sql(SqList l);
bool InitList(SqList &l,int n);
bool Delete_specified(SqList &l,int s,int t);
bool De_s_t(SqList &l,int s,int t);
void Dex_x(SqList &l,int x);
void InitList_scanf(SqList &l,int n);
int main(){
    SqList l;
    /*InitList(l,11);
    print_Sql(l);
   // Reserve_Sql(l);
    //print_Sql(l);
    //Delete
    De_s_t(l,1,5);
    //Delete_specified(l,2,t);
    print_Sql(l);*/
    //printf("\n t is : %d",t);
    int n;
    scanf("%d",&n);
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    for(int i=0;i<n;i++){
       scanf("%d ",&l.data[i]);
    }
    l.length = n;
    print_Sql(l);
    Dex_x( l,2);
    print_Sql(l);
    fclose(stdin);
   // fclose(stdout);
    printf("end");
    return 0;
}
/*
    删除所有与x相同的数
    i++
*/
void Dex_x(SqList &l,int x){
    //int n = l.length;
    int dex = 0;
    int i=0;
        while(i<l.length){
            if(l.data[i]==x)    dex++;
            else{
                l.data[i-dex]=l.data[i];
            }
            i++;

        }
        l.length=l.length - dex;
}
/**
** De_s_t yÓÐÐò
*/
bool De_s_t(SqList &l,int s,int t){
    if(s>=t || l.length==0) return false;
    int i,j;
    for(int i=0;i<l.length && l.data[i]<s;i++);
    if(i>=l.length) return false;
    for(j=i;j<l.length && l.data[j]<=t;j++);
    for(;j<l.length;i++,j++)
        l.data[i] = l.data[j];
    l.length = i+1;
    return true;

}
bool Delete_specified(SqList &l,int s,int t){
    if(l.length <=0 || s>=t) return false;
    int denum = t - s + 1;
    for(int i=s;i<l.length;i++){
        l.data[i-1]=l.data[t];
        t++;
    }
    l.length -= denum;
    return true;
}
 bool InitList(SqList &l,int n){
    if(n>MaxSize) return false;
    for(int i=0;i<n;i++){
        l.data[i] = i;
    }
    l.length = n;
    return true;
 }
bool Reserve_Sql(SqList & l){
    if(l.length == 0) return false;
    if(l.length == 1) return true;
    int n = l.length;
    int m = n%2;
    if(m == 0){
        m = n/2;
        for(int i=n-1;i>m;i--){
            temp(&l.data[i],&l.data[n-1-i]);
        }
    }
    else{
        m = n/2+1;
        for(int i=n-1;i>m;i--){
            temp(&l.data[i],&l.data[n-1-i]);
        }
    }

}
void temp(int *m,int *n){
    int tmp = *m;
    *m = *n;
    *n = tmp;
}
void print_Sql(SqList l){
    for(int i=0;i<l.length;i++){
        printf(" %d ",l.data[i]);
    }
    printf("\n");
}
void InitList_scanf(SqList &l,int n){

}
