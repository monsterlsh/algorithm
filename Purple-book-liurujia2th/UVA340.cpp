#include<iostream>
#include<cstring>
using namespace std;
int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int n,i,tmp,a=0,b=0,cases=0;
    int ch [1010];
    int game[1010];
    int v[10]={0};
    int tmps[10]={0};
    while(scanf("%d",&n)==1 && n){
        printf("Game %d:\n",++cases);
        //memset(v,0,sizeof(v));
        memset(tmps,0,sizeof(tmps));
        memset(v,0,sizeof(v));
       
        for( i=0;i<n;i++){
            scanf("%d",ch+i);
            tmps[ch[i]]++;
            v[ch[i]]++;
        }
        while(true){
            memcpy(v,tmps,sizeof(tmps));
            a=0,b=0;
            for( tmp = 0,i=0;i<n;i++){
                scanf("%d",game+i);
                if(game[i]==ch[i]){a++;v[game[i]]--;}
                if(game[i]==0)tmp++;
            }
            if(tmp==n)break;
            for(i=0;i<n;i++){
                if(game[i]!=ch[i] && v[game[i]]>0){b++;v[game[i]]--;}
                
            }
            printf("    (%d,%d)\n",a,b);
        }
    }
}