/*�����Ĳ���:

�Ѷ���С����:���p��һ������,��0<a<p,��a^(p-1)%p=1.
            ���÷Ѷ���С����,���ڸ���������n,������������ж��㷨,ͨ�� ����d=a^(n-1)%n���ж�n������,��d!=1ʱ,n�϶���������,��d=1ʱ,n   �ܿ���������.

����̽�ⶨ��:���n��һ������,��0<x<p,�򷽳�x^2%p=1�Ľ�Ϊ:x=1��    x=p-1.
            ���ö���̽�ⶨ��,���������÷Ѷ���С�������a^(n-1)%n�Ĺ��� �����Ӷ�����n�Ķ���̽��,һ������Υ������̽������,���ó�n���������Ľ���.

    ���n������,��(n-1)����ż��,��˿���(n-1)=m*(2^q),����m��������(��n��ż��,�������m*(2^q)һ�����Էֽ��һ������������2��k�η�����ʽ),q�ǷǸ�����,��������Ĳ���:
    ����:
         a^m%n; a^(2m)%n; a^(4m)%n; ���� ;a^(m*2^q)%n
    �������������н���Miller����,����Miller����,������Ķ���:

����:��n������,a��С��n��������,��n����aΪ����Miller����,���Ϊ��.
Miller���Խ���k��,������������������Ĵ��������಻�ᳬ��4^(-k).*/


#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define MAX (pow(2.0, 60))                               //������ֵ
#define C 240
#define TIME 12                                                 //Miller���Դ���
using namespace std;

__int64 MIN;

__int64 gcd(__int64 a, __int64 b) //����a��b�����Լ��
 {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

__int64 mod_mult(__int64 a, __int64 b, __int64 n) //����(a*b) mod n
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

__int64 mod_exp(__int64 a, __int64 b, __int64 n) //����(a^b) mod n
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

bool Wintess(__int64 a, __int64 n) //��aΪ����n����Miller���Բ�ʵ�ֶ���̽��
{
    __int64 m, x, y;
    int i, j = 0;
    m = n - 1;
    while (m % 2 == 0) //����(n-1)=m*(2^j)�е�j��m,j=0ʱm=n-1,���ϵĳ���2ֱ��nΪ����
    {
        m = m >> 1;
        j++;
    }
    x = mod_exp(a, m, n);
    for (i = 1; i <= j; i++) {
        y = mod_exp(x, 2, n);
        if ((y == 1) && (x != 1) && (x != n - 1)) //����̽��
            return true; //����trueʱ,n�Ǻ���

        x = y;
    }
    if (y != 1)
        return true;
    return false;
}

bool miller_rabin(int times, __int64 n) //��n����s�ε�Miller����
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

__int64 Pollard(__int64 n, int c) //��n�������ַֽ�,�ҳ�n��һ������,ע������Ӳ�һ������С��
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
        if (y == x) //�����Ѿ����ֹ�,ֱ�ӷ��ؼ���
            return n;
        if (i == k) {
            y = x;
            k = k << 1;
        }
    }
}

void get_small(__int64 n, int c) //�ҳ���С����������
{
    __int64 m;
    if (n == 1)
        return;
    if (miller_rabin(TIME, n)) //�ж��Ƿ�Ϊ����
    {
        if (n < MIN)
            MIN = n;
        return;
    }
    m = n;
    while (m == n) //�ҳ�n��һ������
        m = Pollard(n, c--);
    get_small(m, c); //���ֲ���
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
