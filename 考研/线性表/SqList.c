#include<stdio.h>
#include<stdlib.h>
#define LIST_SIZE 100
#define lISTING 10
typedef struct {
    int  * elem;
    int length;
    int listsize;
}SqList;
bool InitList(SqList & L);
void MergeList(SqList La,SqList Lb,SqList & Lc);
void printfSqList(SqList L){
     for(int i=0;i<L.length;i++){
        printf("%d\n",L.elem[i]);
    }
}

int main(void){
    SqList la,lb,lc;
    InitList(la);
    InitList(lb);
    for(int i=0;i<8;i++){
        scanf("%d",&la.elem[i]);
        la.length++;
    }
    printf("la输入完成 请输入Lb");
    for(int i=0;i<4;i++){
        scanf("%d",&lb.elem[i]);
        lb.length++;
    }
    printf("la : \n");
    printfSqList(la);
    printf("lb : \n");
    printfSqList(lb);
    printf("lc : \n");
    MergeList(la,lb,lc);
    printfSqList(lc);

return 0;
}

bool InitList(SqList & L){
    L.elem = (int *)malloc(LIST_SIZE * sizeof(int));
    if(! L.elem) exit(0);
    L.length = 0;
    L.listsize = LIST_SIZE;
    return true;
}
void MergeList(SqList La,SqList Lb,SqList & Lc){
   int * pa = La.elem;
   int * pb = Lb.elem;
   Lc.listsize = Lc.length = La.length + Lb.length;
   int * pc = Lc.elem = (int *)malloc(Lc.listsize * sizeof(int));
   if(! Lc.elem) exit(0);
   int * pa_last = La.elem + La.length;
   int * pb_last = Lb.elem + Lb.length;
   while(pa <= pa_last && pb <= pb_last) {
    if(*pa <= *pb) *pc++ = *pa++;
    else *pc++ = *pb++;
   }
   while(pa <= pa_last )*pc++ = *pa++;
   while(pb <= pb_last )*pc++ = *pb++;
}
