#include<cstdio>
#include<cmath>
int main(){
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    double x1 = (-b+sqrt(b*b-4*a*c))/(2*a);
    double x2 = (-b-sqrt(b*b-4*a*c))/(2*a);
    printf("%g %g",x1,x2);
}