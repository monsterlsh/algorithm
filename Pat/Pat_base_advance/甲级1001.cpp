//1001 A+B Format
// 数字转字符串
#include<iostream>
#include<string>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int c = a +b;
    string str = to_string(c);
    int i = 0,cn =0;
    if(str[i]=='-')i=1;
    while(i+3<str.length()&&i<str.length())
    {
        str.insert(i+3,"1");
        i = i+3;
    }
    cout<<str<<endl;
}