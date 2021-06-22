#include <iostream>
#include <map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {

    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, m;
    cin >> m >>n;

    //map<int, int> m;
    vector<int>res(n);
    for(int i=0;i<n;i++){
        cin>>res[i];
    }
    while(m--){
        int x,y,xi=-1,yi=-1;
        cin>>x>>y;
       
        for(int i = 0;i<res.size();i++){
            if(res[i]==x)xi=i;
            if(res[i]==y)yi=i;
        }
        if(xi==-1 && yi>=0)printf("ERROR: %d is not found.\n",x);
        else if(yi==-1 && xi>=0)printf("ERROR: %d is not found.\n",y);
        else if(yi==-1 && xi==-1)printf("ERROR: %d and %d are not found.\n",x,y);
        else{
            bool flag = false;
             if(xi>yi){swap(xi,yi);flag=true;}
            int l=0,r=res.size()-1;
            while(l<r){
                int mid = l+1;
                if(xi==l){printf("%d is an ancestor of %d.\n",res[xi],res[yi]);break;}
                while(res[mid]<res[l])mid++;
                if(xi<mid&& yi>=mid){ int xx =flag?res[yi]:res[xi];int yy=flag?res[xi]:res[yi]; printf("LCA of %d and %d is %d.\n",xx,yy,res[l]);break;}
                else if(xi<mid&&yi<mid){l++;r=mid-1;}
                else if(xi>=mid && yi >= mid){l=mid;}
            }
        }
    }
    
    return 0;
}
