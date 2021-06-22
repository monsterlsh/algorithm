#include<iostream>
using namespace std;
#define RE
#define maxn 10
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    string str1;
    size_t alpa[256];
    char c;
    //cin 会把换行符留在输入缓存 那么对于空格呢？Answer:也会把空格留入缓冲区
    while (cin>>str1)
    {
        size_t idx = 0;
        while(scanf("%c",&c)!=EOF && c!='\n'){
            if(c==str1[idx])idx++;
        }
        if(idx==str1.size())printf("Yes\n");
        else printf("No\n");
    }
}
