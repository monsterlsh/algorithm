#include<iostream>
using namespace std;
long mult(long a,long b){
    return a*b;
}

void multscore(long x,long y,long * dest){
    long t = mult(x,y);
    *dest = t;
}
int main(){
    cout<<0<<endl;
}

