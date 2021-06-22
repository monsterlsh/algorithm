#include<iostream>
using namespace std;
int n;
char c;
int main(){
    cin>>n>>c;
    for(int i=0;i<(n+1)/2;i++){
        for(int j = 0;j<n;j++){
            if(i==0||i==(n+1)/2-1||j==0||j==n-1)cout<<c;
            else if(i!=0 && i!=(n+1)/2-1&&j!=0&&j!=n-1)cout<<" ";
            if(j==n-1)cout<<"\n";
        }
    }
    return 0;
}