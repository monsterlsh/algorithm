/*
ID: uplshup1
TASK: commonmultiple
LANG: C++
TIME: 2019年3月18日12:19:31
*/
/**
* test prime
* version 1.0
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#ifndef ll
#define ll long long
#endif

// rand 2 - e
ll rand_Number(ll e){
    return rand()%e+1;;
}
// a*b % c
ll mult_mod(ll a,ll b,ll c){
    a %= c;
    b %= c;
    ll res = 0;
    while(b){
        if(b & 1){
            res += a;
            res %= c;
        }
        a <<= 1;
        if(a >= c)
            a %= c;
        b >>= 1;
    }
    return res;
}

//a^u % num
ll getRemainder(ll a,ll u, ll num){
    ll cur = 1;
    ll nxt = a;
    while (u) {
        if ((u&1) > 0) {
            cur = mult_mod(cur, nxt, num);
        }
        nxt = mult_mod(nxt, nxt, num);
        u = u>>1;
    }
    return cur%num;
}


bool checkPrime(ll num){
    if (num == 2) {
        return true;
    }
    if (num < 2 || num % 2 == 0) {
        return false;
    }
    ll u = num-1;
    int S = 8; //检测次数 取20超时 S -> [8,10]
    while (u % 2 == 0) {
        u /= 2;
    }
    for (int i = 0; i < S; i++) {
        ll a = rand_Number(num-1);
        ll x = getRemainder(a, u, num);
        ll y = x;
        ll tu = u;
        while (tu < num) {
            y = mult_mod(x, x, num);;
            if (y == 1 && x != 1 && x != num-1) {
                return false;
            }
            x = y;
            tu *= 2;
        }
        if (x != 1) {
            return false;
        }
    }
    return true;
}

int main()
{
    fstream fin, fout;
    string inputFilename = "test.in", outputFilename = "test.out";
    fin.open(inputFilename.c_str(), ios::in);
    fout.open(outputFilename.c_str(), ios::out);

    ll n,sum=0;

    while(fin>>n)
    {
        while(n--)
        {
            ll m;
            fin>>m;
            if(checkPrime(m))
            {
                sum++;
                //fout << m << endl;
            }
        }
        fout<<sum<<endl;
        sum = 0;
    }


    return 0;
}
