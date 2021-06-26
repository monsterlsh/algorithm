#include <iostream>
#include <string>
#include<vector>
using namespace std;
#define RE
unsigned n,a,b,c;
vector<unsigned>v(11);
vector<unsigned>vtmp(11);
vector<string>as(11);
void solve(){
    fill(v.begin(),v.end(),0);
    fill(as.begin(),as.end(),"0");
    unsigned nn=n,dex=0;
    while(nn--){
        scanf("%u %u %u",&a,&b,&c);
        v[dex]=c-1;
        if(a>1)
        as[dex].append(a-1,'0');
        as[dex].append(b,'1');
        dex++;
    }
    vtmp.assign(v.begin(),v.end());
    unsigned sleep=0,i=1,j=0;
    for( i = 1;; i++){
        for ( j=0; j < n; j++){
           // cout<<"i:"<<i<<" v[j]:"<<v[j]<<" "<<as[j][v[j]]<<","<<as[j][(v[j]-1+as[j].size())%as[j].size()]<<endl;;
            if(as[j][v[j]]=='0' && as[j][(v[j]+1+as[j].size())%as[j].size()] == '1'){}
            else if(as[j][v[j]]=='1')sleep++;
        }
        //cout<<endl;
        if(sleep==0){sleep=i;break;}
        for ( j=0; j < n; j++){
            if(as[j][v[j]]=='0' && as[j][(v[j]+1+as[j].size())%as[j].size()] == '1' && sleep<=n/2 ){
                v[j]=0;
            }else v[j] = (v[j] + 1 )%(as[j].size());
        }
        for (j=0; j < n && i!=1 && v[j]==vtmp[j]; j++);
        sleep=0;
        if(j==n)break;
    }
    sleep= sleep==0?-1:sleep;
    printf("%d\n",sleep);
}
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    int kase=0;
    while(scanf("%u",&n) && n){
        printf("Case %d: ",++kase);
        solve();
    }
}
