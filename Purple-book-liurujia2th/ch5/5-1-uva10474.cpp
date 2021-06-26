#include <iostream>
#include <string>
#include<sstream>
using namespace std;
#define RE
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif

cout<<string(2,'0');

string str;
while(getline(cin,str)){
    int sum =0,x;
    stringstream ss(str);
    while(ss>>x) sum+=(int)x;
    cout<<sum<<endl;
}
}
