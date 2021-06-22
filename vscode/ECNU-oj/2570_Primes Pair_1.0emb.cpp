#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;
const int maxn = 10005;
bool isPrime[maxn]={false};

bool prime(int n){
    if (n<=6){
        if (n==1 || n==0 || n==4 || n==6) return false;
        else return true;
     }else{
        if (n%6==1 || n%6==5){
            for (int i = 5; i < sqrt(n); i+=6) {
                if (n%i==0 || n%(i+2)==0) return false;
            }
            return true;
        }else return false;
    }
}

void init(){
    for (int i = 1 ; i <maxn ; ++i) {
        if (isPrime[i]==false &&prime(i)){
            int z=2*i;
            while(z<maxn){
                isPrime[z]= true;
                z+=i;
            }
        }else{
            isPrime[i]= true;
        }
    }
}

int main() {
    init();
    int t,n;
    cin>>t;
    for (int p = 0; p < t; ++p) {
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            if (!isPrime[i] && !isPrime[n+1-i]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}