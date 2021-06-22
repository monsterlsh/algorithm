#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const int maxnum=1600000;
char str[maxnum];
bool array[20000000];
int hash[256];

int main()
{
    int n,nc;
    int i,cnt,len,sum,j,res;
    while(scanf("%d%d%s",&n,&nc,str)!=EOF)
    {
        cnt=0;
        memset(hash,0,sizeof(hash));
        memset(array,false,sizeof(array));
        len=strlen(str);
        for(i=0;i<len;i++)
            if(hash[str[i]]==0)   //cnt���Ϊnc-1
                hash[str[i]]=cnt++;
        res=0;
        for(i=0;i+n<=len;i++)
        {
            sum=0;
            for(j=i;j<i+n;j++)
            {
                sum*=nc;   //������Ϊn���Ӵ�������nλnc��������������������nΪnc�������Ķ�Ӧ��ʮ��������
                sum+=hash[str[j]];
            }
            if(!array[sum])
            {
                res++;
                array[sum]=true;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
