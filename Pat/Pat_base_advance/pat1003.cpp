#include<iostream>
using namespace std;
bool judge(string s){
    int a = 0,b=0,i=0,n=s.length();
    while(i<n && s[i]=='A')i++;
    a = i;
    if(i>=n || s[i++]!='P')return false;
    while(i<n && s[i]=='A'){i++;b++;}
    if(i>=n || !b || s[i++]!='T' )return false;
    b = a*b;
   // cout<<b<<endl;
    while(i<n && s[i]=='A'  ){i++;b--;}
    cout<<b<<endl;
    if(i>=n && b<=0)return true;
    else return false;
}
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int n;
    cin>>n;
    string str;
    while (n--)
    {
        cin>>str;
        if(judge(str))cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    
}