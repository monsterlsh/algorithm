#include<iostream>
#include<cctype>
#include<string>
using namespace std;
#define int long long
#define PI pair<int,int>
const int maxm=2e5+5;
int num[45][45];
int a[maxm];
int n;
signed main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){//用字符串读,避免误差
        string s;cin>>s;
        int num=0;
        int cnt=-1;
        for(auto x:s){
            if(isdigit(x)){
                num=num*10+x-'0';
                if(cnt>0)cnt--;
            }else{//小数点
                cnt=9;
            }
        }
        if(cnt==-1)cnt=9;//如果没有小数点
        while(cnt-->0)num=num*10;
        a[i]=num;
    }
    for(int i=1;i<=n;i++){
        int c2=0,c5=0;
        while(a[i]%2==0){
            c2++;
            a[i]/=2;
        }
        while(a[i]%5==0){
            c5++;
            a[i]/=5;
        }
        num[c2][c5]++;
    }
    int ans=0;
    for(int i=18;i<=90;i++){
        for(int j=18;j<=90;j++){
            //枚举结果数对(i,j)
            for(int x=0;x<45&&x<=i;x++){
                for(int y=0;y<45&&y<=j;y++){
                    int xx=i-x,yy=j-y;
                    if(xx<0||xx>=45||yy<0||yy>=45)continue;
                    if(xx==x&&yy==y){//相等的情况特判一下,不能匹配自己
                        ans+=num[x][y]*(num[x][y]-1);
                    }else{
                        ans+=num[x][y]*num[xx][yy];
                    }
                }
            }
        }
    }
    ans/=2;//无序转有序
    cout<<ans<<endl;
    return 0;
}
