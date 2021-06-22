#include<iostream>
using namespace std;
int scores[101] = {0};
int main(){
    int n;cin>>n;
    for(int i=0;i < n;i++){
        int tmp;
        cin>>tmp;
        scores[tmp]++;
    }
    cin>>n;
    for(int i=0;i < n;i++)
    {   int tmp;cin>>tmp;
        if(i!=n-1)
        cout<<scores[tmp]<<" ";
        else cout<<scores[tmp]<<endl;
    }
}