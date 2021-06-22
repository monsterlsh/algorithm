#include<iostream>
#include<cctype>
#include<vector>
#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
bool compare(string a, string b);
string add(string a, string b);
int main(){
   cout<<add("123","99999")<<endl;
   cout<<123+99999<<endl;
}
bool compare(string a, string b)
{
    if (a[0] == '-' && b[0] != '-')
        return 1;
    if (a[0] != '-' && b[0] == '-')
        return 0;
    else if(a[0] == '-' && b[0] == '-'){
        
        a=a.substr(1,a.length()-1);
        b=b.substr(1,b.length()-1);
        
        //return (a.length() > b.length() || ((a.length() ==b.length())&&a>b));
    }
    return a.length() < b.length() || ((a.length() ==b.length())&&a<b);
}
string add(string a, string b)
{
    int i = a.length() - 1;
    int j = b.length() - 1;
    int ch = 0, shang = 0;
    //int n = max(i, j);
    string res = "";
    while (i >= 0 && j >= 0)
    {
        int sum = a[i] + b[j] - '0'-'0' + ch;
        ch = sum / 10;
        shang = sum % 10;
        res += shang + '0';
        i--;
        j--;
    }

    while (i >= 0 && ch != 0)
    {
        int sum= (a[i] + ch - '0') ;
        ch = sum / 10;
        res += sum % 10 + '0';
        i--;
    }
    while (i >= 0) 
        res += a[i--];
    i = j;
    while (i >= 0 && ch != 0)
    {
        int sum= (b[i] + ch - '0') ;
        ch = sum / 10;
        res += sum % 10 + '0';
        i--;
    }
    while (i >= 0)
        res += b[i--];
    if(ch)res+=ch+'0';
    reverse(res.begin(), res.end());
    return res;
}