#include<iostream>
#include<cstring>
#define maxn 10000
using namespace std;
int n;
int arr[maxn][10]={0};

int fn(int dex){
    int c,i=0,num=dex;
    do{
        c = dex%10;
        arr[num][c]++;
        dex /=10;
    }while(dex!=0);
    return i;
}
void p(int des[]){
    for(int i=0;i<10;i++)
    cout<<des[i]<<" ";
    cout<<endl;
}
void dabiao(){
    for(int i=1;i<maxn;i++){
       //cout<<" dex "<<i<<" : "; p(arr[i]);
        memcpy(arr[i],arr[i-1],sizeof(int)*10);
       // cout<<" dex "<<i<<" : "; p(arr[i]);
        fn(i);
       // cout<<"--after dex "<<i<<" : "; p(arr[i]);
    }
}

int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    dabiao();
    scanf("%d",&n);
    int m;
    while(n--){
        //memset(res,0,sizeof(res));
        scanf("%d",&m);
        for(int i=0;i<10;i++) printf("%d%s",arr[m][i],i==9?"\n":" ");
    }
}