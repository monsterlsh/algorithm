/*
ID: uplshup1
PROG: milk2
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<climits>
#define AN
using namespace std;
size_t n,i=0,ma=0,maNomilk=0;
vector<pair<size_t,size_t>>milks;
int main(){
    #ifdef AN
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    #endif
    
    #ifdef RE
    ofstream fout("output.out");
    ifstream fin("input.in");
    #endif
    fin>>n;
    milks.resize(n);
    while(i<n){
        fin>>milks[i].first>>milks[i].second;
        i++;
    }
    sort(milks.begin(),milks.end());
    i=0;
    size_t beg=0,en=0,tmp;
    ma = milks[en].second-milks[beg].first;
    while(i<n){
        if(milks[en].second<milks[i].first){
            tmp = milks[i].first-milks[en].second;
            maNomilk = max(maNomilk,tmp);
            beg = en = i;
            if(i==n-1){
                tmp = milks[i].second-milks[i].first;
                ma = max(ma,tmp);
            }
        }else if(milks[en].second<milks[i].second) {
            en = i;
            tmp = milks[en].second-milks[beg].first;
            ma = max(ma,tmp);
         }
         
        i++;
    }
    //if(milks[en].second>=milks[n-1].second )ma=milks[en].second-milks[beg].first,maNomilk=n==1?0:maNomilk;
    fout<<ma<<" "<<maNomilk<<endl;
    return 0;
}