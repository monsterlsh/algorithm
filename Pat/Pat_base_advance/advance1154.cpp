#include<iostream>
#include<set>
using namespace std;
struct node{
    int i,j;
    bool flag = false;
}edge[10001];
//int edge[10001][10001];
int colors[10001]={0};
set<int>s;
void f(int n,int m);
void f(int n,int m){
        s.clear();
        
            for(int j=0;j<m;j++){
                //cout<<edge[j].i<<" "<<edge[j].j << endl;
                if(edge[j].flag && colors[edge[j].i]==colors[edge[j].j]){printf("No\n");return;}
            }
        
        
        for(int i=0;i<n;i++) {s.insert(colors[i]);}
       
        printf("%d-coloring\n",s.size());
        
}

int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        edge[i].i=x;
        edge[i].j=y;
        edge[i].flag=true;
    }
    int k;
    scanf("%d",&k);
    while(k--){
        for(int i=0;i<n;i++) {scanf("%d",&colors[i]);}
        f(n,m);
        
    }
}
