
#include<iostream>
#include<algorithm>
#include<cctype>
#include<set>
#include<vector>
using namespace std;

#define RE
void move(vector<size_t>& alls){
    size_t n=alls.size();
    size_t moves=0,dex=0,i;
    while(alls[i]==0){
        moves++;
        i++;
    }
    while(dex+moves<n-1){
        i = dex+moves;
        while(alls[i+1]==alls[i]){i++;moves++;}
        alls[dex]=alls[dex+moves];
        dex++;
    }
}
int main(){
    #ifdef RE
    freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif
    vector<size_t>alls(2500,0);
    size_t i=1,en=0;
    alls[1]=1;alls[2]=2;alls[3]=3;alls[4]=5;
    while(en!=1500){
        en = i+3;
        for(size_t j=0;j<3;j++)
        alls[++en]=(alls[i+j]*2);
        for(size_t j=0;j<3;j++)
        alls[++en]=(alls[i+j]*3);
        for(size_t j=0;j<3;j++)
        alls[++en]=(alls[i+j]*5);
      
        i+=3;
    }
    sort(alls.begin(),alls.end());
    //move(alls);
    set<size_t>re;
    for(auto x:alls)
    {
        //if(x)re.insert(x);
        //if(re.size()==1500)break;
        cout<<x<<endl;
    }
    cout<<"res:"<<*re.end()<<endl;
}