/*素数的测试:

费尔马小定理:如果p是一个素数,且0<a<p,则a^(p-1)%p=1.
            利用费尔马小定理,对于给定的整数n,可以设计素数判定算法,通过 计算d=a^(n-1)%n来判断n的素性,当d!=1时,n肯定不是素数,当d=1时,n   很可能是素数.

二次探测定理:如果n是一个素数,且0<x<p,则方程x^2%p=1的解为:x=1或    x=p-1.
            利用二次探测定理,可以再利用费尔马小定理计算a^(n-1)%n的过程 中增加对整数n的二次探测,一旦发现违背二次探测条件,即得出n不是素数的结论.

    如果n是素数,则(n-1)必是偶数,因此可令(n-1)=m*(2^q),其中m是正奇数(若n是偶数,则上面的m*(2^q)一定可以分解成一个正奇数乘以2的k次方的形式),q是非负整数,考察下面的测试:
    序列:
         a^m%n; a^(2m)%n; a^(4m)%n; …… ;a^(m*2^q)%n
    把上述测试序列叫做Miller测试,关于Miller测试,有下面的定理:

定理:若n是素数,a是小于n的正整数,则n对以a为基的Miller测试,结果为真.
Miller测试进行k次,将合数当成素数处理的错误概率最多不会超过4^(-k).*/


#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define MAX (pow(2.0, 60))                               //标记最大值
#define C 240
#define TIME 12                                                 //Miller测试次数
using namespace std;

__int64 MIN;

__int64 gcd(__int64 a, __int64 b) //计算a和b的最大公约数
 {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

__int64 mod_mult(__int64 a, __int64 b, __int64 n) //计算(a*b) mod n
{
    __int64 s = 0;
    a = a % n;
    while (b) {
        if (b & 1) {
            s += a;
            if (s >= n)
                s -= n;
        }
        a = a << 1;
        if (a >= n)
            a -= n;
        b = b >> 1;
    }

    return s;
}

__int64 mod_exp(__int64 a, __int64 b, __int64 n) //计算(a^b) mod n
{
    __int64 d = 1;
    a = a % n;
    while (b >= 1) {
        if (b & 1)
            d = mod_mult(d, a, n);
        a = mod_mult(a, a, n);
        b = b >> 1;
    }
    return d;
}

bool Wintess(__int64 a, __int64 n) //以a为基对n进行Miller测试并实现二次探测
{
    __int64 m, x, y;
    int i, j = 0;
    m = n - 1;
    while (m % 2 == 0) //计算(n-1)=m*(2^j)中的j和m,j=0时m=n-1,不断的除以2直至n为奇数
    {
        m = m >> 1;
        j++;
    }
    x = mod_exp(a, m, n);
    for (i = 1; i <= j; i++) {
        y = mod_exp(x, 2, n);
        if ((y == 1) && (x != 1) && (x != n - 1)) //二次探测
            return true; //返回true时,n是合数

        x = y;
    }
    if (y != 1)
        return true;
    return false;
}

bool miller_rabin(int times, __int64 n) //对n进行s次的Miller测试
{
    __int64 a;
    int i;
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    srand(time(NULL));
    for (i = 1; i <= times; i++) {
        a = rand() % (n - 1) + 1;
        if (Wintess(a, n))
            return false;
    }
    return true;
}

__int64 Pollard(__int64 n, int c) //对n进行因字分解,找出n的一个因子,注意该因子不一定是最小的
{
    __int64 i, k, x, y, d;
    srand(time(NULL));
    i = 1;
    k = 2;
    x = rand() % n;
    y = x;
    while (true) {
        i++;
        x = (mod_mult(x, x, n) + c) % n;
        d = gcd(y - x, n);
        if (d > 1 && d < n)
            return d;
        if (y == x) //该数已经出现过,直接返回即可
            return n;
        if (i == k) {
            y = x;
            k = k << 1;
        }
    }
}

void get_small(__int64 n, int c) //找出最小的素数因子
{
    __int64 m;
    if (n == 1)
        return;
    if (miller_rabin(TIME, n)) //判断是否为素数
    {
        if (n < MIN)
            MIN = n;
        return;
    }
    m = n;
    while (m == n) //找出n的一个因子
        m = Pollard(n, c--);
    get_small(m, c); //二分查找
    get_small(n / m, c);
}

int main() {
    int total;
    __int64 n;
    scanf("%d", &total);
    while (total--) {
        scanf("%I64d", &n);
        MIN = MAX;
        if (miller_rabin(TIME, n))
            printf("Prime\n");
        else {
            get_small(n, C);
            printf("%I64d\n", MIN);
        }
    }
    return 0;
}
