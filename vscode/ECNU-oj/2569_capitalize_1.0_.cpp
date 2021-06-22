#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
using namespace std;

int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    string str;
    getline(cin,str);
    for(int i=0;i<str.length();i++){
        if(islower(str[i]))str[i] = toupper(str[i]);
    }
    cout<<str<<endl;
    return 0;
}