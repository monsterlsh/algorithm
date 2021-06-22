#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ll;
 ll m,n,t;
vector<ll>nt;
vector<pair<ll,ll>>res;

vector<ll>ans;
ll index=0;
bool compre(pair<ll,ll>a,pair<ll,ll>b){
    if(a.second-a.first > b.second-b.first) return true;
    else if(a.second-a.first == b.second-b.first && a.first<b.first)return true;
    return false;
}
void preup(){
    pair<ll,ll> tmp = res[index];
    ll i = index/2;
    for(;i>1;i /=2){
        if(res[i].second-res[i].first < tmp.second-tmp.first ) res[i]=res[i/2];
        else if(res[i].second-res[i].first == tmp.second-tmp.first && res[i].first > tmp.first)res[i]=res[i/2];
        else break;
    }
    res[i]=tmp;
}
void add(ll x,ll mid,ll y){
    if(x>y)return;
    if(mid == -1){
        
        res[++index]=( make_pair(x,y));
        ll hole = index;
        
        preup();
        return ;
    }
    if(x<=mid-1){
        res[++index]=( make_pair(x,mid-1));
        preup();
    }
    
    if(y>=mid+1){
        res[++index]=( make_pair(mid+1,y));
        preup();
    }
}
void deletes(){
    pair<ll,ll> tmp = res[index],left,right;
    res[index] = res[1];
    res[1]=tmp;
    index--;
    int i = 1;
    for(;i<=index/2;){
        left = res[2*i];
        if(2*i+1<=index)right = res[2*i+1];
        else {
            if(compre(left,res[i])){swap(left,res[i]);}
            break;
        }
        if(compre(left,right)&&compre(left,res[i])){
            swap(left,res[i]);
            i *=2;
        }
        else if(compre(right,left)&&compre(right,res[i])) {
            swap(right,res[i]);
            i =i*2+1;
        }
        else break;
    }

}

int main(){
   // res[0]=( make_pair(0,0));
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin>>m>>n>>t;
    ans.resize(m+1);
    res.resize(m+1);
    vector<ll>idx(n+1);
    for(ll i=1;i<=n;i++){
        cin>>idx[i];
    }//for
     add(1,-1,idx[1]-1);
    for(ll i=2;i<=n;i++){
        
        add(idx[i-1]+1,-1,idx[i]-1);
        if(i==n)add(idx[i]+1,-1,m);
    }//for
    for(int i=1;i<=index;i++){
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
   // bool flag = true;
   /* while (!res.empty())
    {
        pair<ll,ll> a = res[1];
        if(a.first==a.second)break;
        ll mid = (a.first+a.second)/2;
        ans[++n]=mid;
        deletes();
        add(a.first,mid,a.second);
    }
    for(ll i=1;i<=m;i++){
        if(ans[i])ans[++n]=i;
    }
    while(t--){
        ll tmp;
        cin>>tmp;
        cout<<ans[tmp]<<endl;
    }*/
    
    
    
}