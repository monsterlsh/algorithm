/*
ID: uplshup1
TASK: commonmultiple
LANG: C++
TIME: 2019年3月18日11:27:33
*/
/**
* test multiple
* version 1.0
*/
/*
* 最小公倍数和最大公约数
gcd(ka, kb) = k * gcd(a, b)

lcm(ka, kb) = k * lcm(a, b)

lcm(S/a, S/b) = S/gcd(a, b)
*/
/*#include<cstdio>
typedef long long LL;
void extend_Eulid(LL a, LL b, LL &x, LL &y, LL &d){
    if (!b) {d = a, x = 1, y = 0;}
    else{
        extend_Eulid(b, a % b, y, x, d);
        y -= x * (a / b);
    }
}
int main(){
    LL a, b, d, x, y;
    while(~scanf("%lld%lld", &a, &b)){
        extend_Eulid(a, b, x, y, d);
        printf("%lld*%lld + %lld*%lld = %lld\n", x,a, y,b ,d);
    }
}*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int cm(int n,int m)
{
    int max1,min1,remain,shang;

    max1 = max(n,m);
    min1 = min(n,m);

    remain = max1 % min1;
    if(remain == 0) return max1;

    shang  = cm(min1,remain) / remain;
    return shang * max1;

}

int main()
{
    fstream fin, fout;
    string inputFilename = "test.in", outputFilename = "test.out";
    fin.open(inputFilename.c_str(), ios::in);
    fout.open(outputFilename.c_str(), ios::out);

    int n,m;

    while(fin>>n>>m)
    {
         fout<<cm(n,m)<<endl;
    }

    return 0;
}