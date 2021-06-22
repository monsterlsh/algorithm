#include<iostream>
#include<cstring>
using namespace std;
struct node{
    int num[10005];
    int len;
}a,ans;
char s[1005];
int main(){
    freopen("input.in","r",stdin);  
    freopen("output.out","w",stdout);
    int t,b,i;
    while(scanf("%s",&s)!=EOF){
        a.len=(int)strlen(s);
        memset(a.num,0,sizeof(a.num));
        for(int i=0;i<a.len;i++){
            a.num[i]=s[a.len-i-1]-'0';
        }
        scanf("%d",&b);
        memset(ans.num,0,sizeof(ans.num));
        ans.len=1;
        for(i=a.len-1;i>=0;i--){
            if(i!=0)
            a.num[i-1] += a.num[i]%b*10;
            ans.num[i] = a.num[i]/b;
            if(ans.num[i]&& ans.len==1) ans.len=i+1;
        }
        for(i=ans.len-1;i>=0;i--){
            printf("%d",ans.num[i]);
        }
        printf(" %d\n",a.num[0]%b);
    }
}