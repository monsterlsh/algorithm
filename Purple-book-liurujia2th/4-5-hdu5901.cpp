#include <iostream>
#include <cstring>
using namespace std;
#define RE
const size_t maxn= 1000000;
const size_t maxInput = 10000000000;
 
size_t Prime[maxn]={0};
size_t n,maxs=500,begins=2,c=0;
void countPrime(){
    //memset(Prime,0,sizeof(Prime));
    if( Prime == nullptr) return;
    size_t j;
    for(size_t i=begins;i<=maxs;i++){
        //for(j=0;)
        for(j=0;c!=0 && Prime[j]&& i%Prime[j]!=0 && j<=c;j++);
        if(c==0 || j==c)
        Prime[c++]=i;
    }
}
size_t solve(size_t dex,size_t end){
    size_t i=dex,j=c,mid=(i+j)/2;
    while(i<j && i!=mid){
        if(Prime[mid]<n)i=mid;
        else if(Prime[mid]>n)j=mid-1;
        else if(Prime[mid]==n)return mid+1;
        mid = (i+j)/2;
    }
    if(Prime[i]>n)return i;
    else return i+1;
    /*while(Prime[i]<n)i++;
    if(Prime[i]>=n)return (i+1);*/
}
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
countPrime();
size_t next = 0,fi=0,en=500;
while(scanf("%zu",&n)!=EOF){
    if(n>maxs)
    {
        begins = maxs+1;
        maxs =n;
        countPrime();
        printf("%zd\n",c);
    }else{
        
        next = solve(fi,en);
        printf("%zd\n",next);
    }
   
}
}
