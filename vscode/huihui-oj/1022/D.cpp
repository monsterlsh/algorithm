#include<iostream>
#include<cstdio>
using namespace std;
void swap(double &a,double &b){
    double t = a;
    a = b;
    b = t;
}
int main(){
    
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    double a,b;
    scanf("%lf %lf",&a,&b);
    printf("%g %g\n",a,b);
    swap(a,b);
    printf("%g %g",a,b);
    return 0;
}