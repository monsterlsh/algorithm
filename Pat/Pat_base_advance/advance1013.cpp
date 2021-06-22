#include<iostream>
#include<vector>
using namespace std;
int repair(int citys[][1001],int lost,int n);

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int citys[1001][1001]={0};
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        citys[x][y]=1;
         citys[y][x]=1;
    }
    //cout<<repair(citys,1,n);
    for(int i=0;i<k;i++){
        int lost;
        scanf("%d",&lost);
        printf("%d\n",repair(citys,lost,n));
    }
    return 0;
}
int repair(int citys[][1001],int lost,int n){
    if(lost>n)return 0;
    vector<bool>v(n+1,false);
    v[lost]=true;
    int bridges = 0;
    for(int i=1;i<=n;i++){
        if(citys[lost][i]){citys[lost][i]=0;citys[i][lost]=0;}
    }
    //return 0;
    for(int i=1;i<=n;i++){
        if(v[i]==false){
            
        }
        for(int j=1;j<=n;j++){

        }
    }
     for(int i=1;i<=n;i++){
        if(citys[lost][i]){citys[lost][i]=1;citys[i][lost]=1;}
    }
    if(bridges!=0)return bridges-1;
    else return 0;
}