#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;

int n,m;
char s[10][10];//����
int a[10];//���ÿһ���Ƿ������ӣ�������Ϊ1��������Ϊ0
int tot,cont;//�ܷ��������ѷ����������ӵĸ���

void dfs(int cur)
{
    if(cont == m)  //���Ӹ����ﵽҪ�󣬷�����+1������
    {
        tot++;
        return ;
    }
    if(cur >= n)//���ѳ������⣬����
        return ;
    for(int j = 0;j < n;j++)
     {
        if(!a[j] && s[cur][j] == '#')
        {
            a[j] = 1;//���Ϊ1
            cont++;
            dfs(cur + 1);
            a[j] = 0;//������
            cont--;
        }
     }
    dfs(cur + 1); //cur�в�������
}

int main()
{
    while(~scanf("%d %d",&n,&m))
    {
        if(n == -1 && m == -1)
            break;
        getchar();
        tot = 0;
        cont = 0;
        memset(a,0,sizeof(a));//����ǳ�ʼ��Ϊ0
        for(int i = 0;i < n;i++)
        {
            gets(s[i]);
        }
        dfs(0);
        printf("%d\n",tot);
    }
    return 0;
}
