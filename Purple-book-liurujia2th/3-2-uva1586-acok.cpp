#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
int num ;
//noac
int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    scanf("%d",&num);
    getchar();
    char ch,pre;
    double sum=0.0;
    int eof,tmp=0;
    int atoms[5]={0};
    atoms[4]=-1;
    while(num--){
        sum=0.0;
        tmp=0;
        memset(atoms,0,sizeof(atoms));
        atoms[4]=-1;
        while((eof=scanf("%c",&ch)!=EOF) && ch!='\n'){
            if(!isdigit(ch) && atoms[4]>=0 ){
                atoms[atoms[4]]+=tmp;
                
                if(tmp==0)atoms[atoms[4]]++;
                tmp=0;
            }           
            if(ch=='C') atoms[4]=0;
            else  if(ch=='H')atoms[4]=1;
            else  if(ch=='O')atoms[4]=2;
            else  if(ch=='N') atoms[4]=3;
            //tmp += wrong
            if(isdigit(ch))  tmp = tmp*10+(ch-'0');
            else tmp=0;
           
        }
        atoms[atoms[4]]+=tmp;
        if(tmp==0)atoms[atoms[4]]++;
        sum += atoms[0]*12.01 + 1.008*atoms[1]+16.00*atoms[2]+14.01*atoms[3];
        printf("%.3lf\n",sum);
    }
}