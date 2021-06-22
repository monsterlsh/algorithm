#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string n;
bool palindromic(string & str){
    int n=str.length();
    if(n==1)return true;
    for(int i=0;i<n/2;i++){
        if(str[i]!=str[n-1-i]) return false;
    }
    return true;
}
int main(){
    cin>>n;
    int x=0;
    while(++x <=10 && !palindromic(n)){
        int len = n.length()-1;
        string tmp = n;
        reverse(tmp.begin(),tmp.end());
        cout<<n<<" + "<<tmp<<" = ";
        string str="";
        int ch=0;
        for(int i=len;i>=0;i--){
            int x = n[i]-'0'+tmp[i]-'0'+ch;
            ch = x/10;
            x =x%10;
           // cout<<" ???"<<x<<" ";
            str += x+'0';
        }
        if(ch) str += ch+'0';
        reverse(str.begin(),str.end());
        n=str;
        cout<<n<<endl;
    }
    if(x>10) cout<<"Not found in 10 iterations.\n";
    else cout<<n<<" is a palindromic number."<<endl;
}