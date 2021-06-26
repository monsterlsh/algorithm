//周期串,使用环形串的方法求解
#include<iostream>
#include<cstring>
using namespace std;
int main(void)
{
    int N;
    char str[100];
    cin>>N;
    while(N--)
    {
        cin>>str;
        int len=strlen(str);
        int t=1;
        while(1)
        {
            int c=0;
            for(int i=0;i<len;++i)
            {
                if(str[i]==str[(i+t)%len])  //看一看转几个字符能够恢复原位
                    ++c;
            }
            if(c==len)
                break;
            ++t;
        }
        cout<<t<<endl;
        if(N!=0)
            cout<<endl;
    }
    return 0;
}