
#include<iostream>
#include<algorithm>
#include<cctype>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;
#define RE
int main(){
    #ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
}
template<typename T>
T sum(T*begin,T *end){
    T *p  =  begin;
    T ans=0;
    for(;p!=end;p++)  ans = ans+*p // ans += *p;
    return sum;
}
struct Point{
    int x,y;
    Point(int x=0,int y=0):x(x),y(y){}
};
Point operator + (const Point & A,const Point & B){
    return Point(A.x+B.x,A.y+B.y);
}
ostream &   operator << (ostream & out ,const Point &p){
    out <<" "<<p.x<<","<<p.y<<endl;
    return out;
}
