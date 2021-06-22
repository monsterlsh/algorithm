#include<iostream>
#include<vector>
using namespace std;
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
   int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}