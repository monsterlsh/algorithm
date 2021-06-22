/***
 * 
 * 
 * 
 * 
 * 按数据中1的位数排序
 */
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;
struct node{
    string s;
    int num;
};
bool cmp(const node &a, const node &b);
int compute(string s);
bool compare(string a, string b);

bool cmp(const node &a, const node &b)
{
    
    if (a.num == b.num)
    {
        return compare(a.s, b.s);
        //return a.s<b.s;
    }
    return a.num > b.num;
}
int compute(string str)
{
    int s[20];
    int output[66]={0};
    int sum = 1, d = 0, k = 63,n=0;
    bool zhengshu = false;
    if(str[0]=='-')str= str.substr(1,str.length()-1);
    else zhengshu = true;
    //cout<<"str:"<<str<<endl;
    for(int i=0;i<str.length();i++){
        s[i] = str[i]-'0';
    }
    n = str.length();
    //这个循环有bug
    while(sum!=0){
        sum =0;
        for (int i = 0; i < n; i++){
            d = (s[i])/2;
            sum+=d;
            if(i ==n-1) {
                output[k--] = (s[i])%2;
            }
            else s[i+1] += ((s[i])%2)*10;
            s[i]=d;
        }
       // cout<<" k : "<<k<<", sum : "<<sum<<endl;
    }
    if(k==63)return 0;
    sum=0; 
    if(!zhengshu){
        for(int i=0;i<64;i++)
            output[i] = output[i]==1?0:1;
        int ch = 1;
        for(int i=63;i>=0;i--){
            int x =  (output[i]+ch);
            output[i] = x%2;
            ch = x/2;
            //if(ch == 0)break;
        }
    }
    /*
    cout<<"[";
    for(int i=0;i<64;i++){
       cout<<output[i];   
    }   
    cout<<"]";*/
    for(int i=0;i<64;i++){
       sum += output[i]==1?1:0;   
    }
    
    //cout<<"after sum : "<<sum<<endl;
    return sum;
   
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
        return (a.length() > b.length() || ((a.length() ==b.length())&&a>b));
    }
    return a.length() < b.length() || ((a.length() ==b.length())&&a<b);
}
   
int main()
{
     freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    scanf("%d", &t);
    int c = 0;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<node> res(n);
        for (int i = 0; i < n; i++)
        {
            cin >> res[i].s;
            res[i].num = compute(res[i].s);
        }
       /* cout<<endl;
       for (int i = 0; i < n; i++)
        {
           cout<<res[i].s<<" ";
        }
        cout<<endl;
        for (int i = 0; i < n; i++)
        {
           cout<<res[i].num<<" ";
        }
        cout<<endl;*/
        sort(res.begin(), res.end(),cmp);
        printf("case #%d:\n",c++);
        for(int i=0;i<n;i++){
            const char * ch = res[i].s.c_str();
            if(i!=n-1)
            printf("%s ",ch);
            else printf("%s\n",ch);
        }
    }
    
}