/*
ID: uplshup1
TASK: gcd2
LANG: C++
TIME: 2019年3月18日22:36:58
*/
/**
* test gcd
* version 1.0
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int gcd(int  n,int  m)
{
    if(n > m) swap(n,m);
    return m % n == 0 ? n : gcd(n,m%n);
}
int gcd2(int n,int m)
{
    if(m / n == 2) return n;
    if(m / n == 1) return 2*n;
    for(int i = 2; ; i++)
    {
        if(gcd(i*n,m)!=n) continue;
        else return i*n;
    }
}

int main()
{
    fstream fin, fout;
    string inputFilename = "test.in", outputFilename = "test.out";
    fin.open(inputFilename.c_str(), ios::in);
    fout.open(outputFilename.c_str(), ios::out);

    int n;

    while(fin>>n)
    {
        while(n--)
        {
            int a,b;
            fin>>a>>b;
            fout<<gcd2(b,a)<<endl;
        }
    }

    return 0;
}
