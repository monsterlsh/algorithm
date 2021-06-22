#include<iostream>
#include<unordered_map>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
int n;
string id,sch;
int score;
struct node{
    int scores;
    //string school;
    int n;
};

typedef pair<string,node> pp;


bool cmp(const pp&a,const pp  & b){
    
    if(a.second.scores!=b.second.scores)
    return a.second.scores>b.second.scores;
    else if(a.second.n!=b.second.n) return a.second.n<b.second.n;
    else return a.first<b.first;;
}

unordered_map<string,node>v;
int main(){
     freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    cin>>n;
    while(n--){
        cin>>id>>score>>sch;
        for(int i=0;i<sch.size();i++){
            if(isupper(sch[i])) sch[i]=tolower(sch[i]);
        }
          v[sch].n++;
        switch (id[0])
        {
        case 'A': v[sch].scores+=score;
            break;
        case 'B': v[sch].scores+=score/1.5;
            break;
        case 'T': v[sch].scores+=score*1.5;
            break;
        default:
            break;
        }
        
    }
    vector<pp>res(v.begin(),v.end());
    sort(res.begin(),res.end(),cmp);
    int pre=-1,rank=0;
    cout<<(int)res.size()<<endl;
    for(int i=0;i<res.size();i++){
        if(pre!=res[i].second.scores) rank = i+1;
        pre = res[i].second.scores;
        //cout<<"sada"<<rank<<endl;
        printf("%d %s %d %d\n",rank,res[i].first.c_str(),res[i].second.scores,res[i].second.n);
        
        
    }

}
