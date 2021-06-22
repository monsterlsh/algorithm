#include <iostream>
#include <map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int n, a, num = 0;
    cin >> n;
    //map<int, int> m;
    vector<int>res(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        //m[a]++;
        res[i]=a;
    }
    /*while(++num)
        if (m[num] == 0) break;
    cout << num;
    cout<<"sort\n";*/
    sort(res.begin(),res.end());
    int i=0;
    while(i<n && res[i]<=0)i++;
    if(i==n || res[i]!=1)cout<<1;
    else {

        while(i<n-1 && (res[i]==res[i+1]-1 || res[i]==res[i+1]))i++;
        cout<<res[i]+1<<endl;
         
    }
    
    return 0;
}