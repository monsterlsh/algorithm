// ？？？ 欧拉函数？？？
/*
ID: uplshup1
TASK: findfriends
LANG: C++
TIME: 2019年3月18日23:18:08
*/
/*
* 参考别人的
*/
#include <iostream>
#include <cstring>

using namespace std;

/*
*  合数的分解需要先进行素数的筛选
*  factor[i][0]存放分解的素数
*  factor[i][1]存放对应素数出现的次数
*  fatCnt存放合数分解出的素数个数(相同的素数只算一次)
*/

const int MAXN = 40000 + 10;

int n;
int prime[MAXN + 1];

//  获取素数
void getPrime()
{
    memset(prime, 0, sizeof(prime));
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    return ;
}

long long factor[100][2];
int fatCnt;

//  合数分解
int getFactors(long long x)
{
    fatCnt = 0;
    long long tmp = x;
    for (int i = 1; prime[i] <= tmp / prime[i]; i++)
    {
        factor[fatCnt][1] = 0;
        if (tmp % prime[i] == 0)
        {
            factor[fatCnt][0] = prime[i];
            while (tmp % prime[i] == 0)
            {
                factor[fatCnt][1]++;
                tmp /= prime[i];
            }
            fatCnt++;
        }
    }
    if (tmp != 1)
    {
        factor[fatCnt][0] = tmp;
        factor[fatCnt++][1] = 1;
    }
    return fatCnt;
}
/*
*  分解质因数法求解，getFactor(n)函数见《合数相关》
*/
int main(int argc, const char * argv[])
{
    getPrime();

    int T;
    cin >> T;

    while (T--)
    {
        cin >> n;
        getFactors(n);
        int ret = n;
        for (int i = 0; i < fatCnt; i++)
        {
            ret = (int)(ret / factor[i][0] * (factor[i][0] - 1));
        }

        cout << ret << '\n';
    }

    return 0;
}