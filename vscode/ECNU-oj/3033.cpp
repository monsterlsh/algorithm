/**
 * https://acm.ecnu.edu.cn/problem/3033/
 * 3033. 删除子串
单点时限: 2.0 sec

内存限制: 256 MB

给定字符串  () 和字符串  ()，在  中自左至右依次查找其中的子串  并将其删除，输出剩余字符串。

输入格式
第 1 行：一个整数  () 为问题数。

第 2~ 行，每行一组测试数据，包括由一个空格分开的两个字符串 （ 中只含有大小写英文字母）。

输出格式
对每个测试数据，首先输出一行问题的编号（0 开始编号，格式：case #0: 等）。在接下来一行中输出在  中删除其含有的子串  后剩余的字符串。

样例
 */ 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    scanf("%d",&t);
    int casenum = 0;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        string::size_type position=0 ; 
        vector<string::size_type>indexs;
        while((position=s1.find(s2,position))!=s1.npos){
            indexs.emplace_back(position);
            position += s2.size();
        }
        for(int i=0;i<indexs.size();i++){
            s1.erase(indexs[i]-s2.size()*i,s2.size());
        }
        printf("case #%d:\n",casenum++);
        cout<<s1<<endl;
    }
    return 0;
}