#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    string a,b;
    char pa,pb;
    int xa=0,xb=0;
    cin>>a>>pa>>b>>pb;
   // cout<<a<<" "<<pa<<" "<<b<<" "<<pb<<endl;
    int i=0;
    string sa="";
    string sb="";
    while(i<a.size() && i<b.size()){
        if(a[i]==pa)sa.push_back(pa);
        if(b[i]==pb)sb.push_back(pb);
        i++;
    }
    while(i<a.size())if(a[i++]==pa)sa.push_back(pa);
    while(i<b.size())if(b[i++]==pb)sb.push_back(pb);
    //cout<<sa<<" "<<sb<<endl;
    if(!sa.empty())xa=atoi(sa.c_str());
    if(!sb.empty())xb=atoi(sb.c_str());
    cout<<(xa+xb)<<endl;

}