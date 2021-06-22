#include<iostream>
#include<cmath>
using namespace std;
void find(int a);
int main(){
    int n;cin>>n;
   
    for(int i = 0;i<n;i++){
        int tmp;
        cin>>tmp;
        find(tmp);
    }
   // system("pause");
}
void find(int a){
    if(a == 1) cout<<a<<endl;
    else {
        a = (a-1)<<1;
        int use = sqrt(a);
        if(use * (use+1)==a) cout<<1<<endl;
        else cout<<0<<endl;
    }
}