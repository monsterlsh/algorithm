#include<stdio.h>
int main(){
    long long a, b; //整数部 小数部
    scanf("%lld.%lld", &a, &b);
    a *= 1000000000;
    a += b;
    long long c, d;
    scanf("%lld.%lld", &c, &d);
    c *= 1000000000;
    c += d;
    a %= c; //转换为整数取模
    c = a % 1000000000;
    a /= 1000000000;
    printf("%lld.", a);
    printf("%09lld", c);
    return 0;
}