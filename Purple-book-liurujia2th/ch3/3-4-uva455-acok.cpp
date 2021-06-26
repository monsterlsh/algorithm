#include<iostream>
using namespace std;
//ac
int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int n;
    scanf("%d",&n);
    while(n--){
        string str;
        cin>>str;
        size_t  i=1,cnt=0;
        while(++cnt<=str.length()/2){
            if(str.size()%cnt!=0)continue;
            i=cnt;
            for(;i+cnt<str.size();i+=cnt){
                //cout<<str.substr(i,cnt)<<" "<<str.substr(i-cnt,cnt)<<(str.substr(i,cnt)==str.substr(i-cnt,cnt))<<endl;
                if(str.substr(i,cnt)!=str.substr(i-cnt,cnt))break;
            }
            if(str.substr(i,cnt)==str.substr(i-cnt,cnt)){ break;}
            //if(i==str.size()-1)break;
        }
        if(cnt>str.length()/2)cnt=str.size();
        printf("%zd\n",cnt);
        if(n!=0)cout<<endl;

    }
}