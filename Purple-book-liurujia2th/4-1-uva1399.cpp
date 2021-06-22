#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
 #define RE

int main()
{
#ifdef RE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    string ciper,message;
    while(cin>>ciper>>message){
        size_t n = ciper.length();
        if(n!=message.length())continue;
        for(size_t i=0;i<message.length();i++){
            message[i] = ((message[i]-'A')%26+1)%26+'A';
        }
        sort(message.begin(),message.end());
        sort(ciper.begin(),ciper.end());
        size_t i =0;
        for(;i<n;i++){
            if(ciper[i]!=message[i]){
                printf("NO\n");
                break;
            }
        }
        if(i==n)
        printf("YES\n");
    }
}
