#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n,score,max=INT_MIN,min=INT_MAX;
    cin>>n;
    string name,id,maxname,maxid,minname,minid;
    while(n--){
        cin>>name>>id>>score;
        if(score>max){maxname = name;maxid=id;max = score;}
        if(score<min){minname=name;minid=id;min=score;}
    }
    cout<<maxname<<" "<<maxid<<endl;
    cout<<minname<<" "<<minid<<endl;
}