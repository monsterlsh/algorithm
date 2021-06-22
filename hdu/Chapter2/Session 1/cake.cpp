/*
ID: uplshup1
TASK: commonmultiple
LANG: C++
TIME: 2019年3月18日12:19:31
*/
/**
* test cake
* version 1.0
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

//n <= m
int cakes(int  &n,int & m)
{
    int tmp = n;
    if(n == m)return n;
    if(n == 1)return m;
    int gap = m - n;
    if(gap > n) swap(gap,n);
   // cout<<"gap : " << gap<<", n : " << n << endl;
    return tmp+cakes(gap,n);
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
        if(n > m) swap(n,m);
        fout<<cakes(n,m)<<endl;
        //fout << n << " " << m<< endl;
    }

    return 0;
}
