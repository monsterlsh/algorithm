#include<iostream>
#include<cstdio>

using namespace std;

int n;
int matri[210][210];
int dx[]={1,1,-1,-1},cx[]={-1,0,1,0};
int dy[]={-1,1,1,-1},cy[]={0,-1,0,1};

bool in_matrix(int x,int y)
{
    if(x<0||x>=n) return false;
    if(y<0||y>=n) return false;
    return true;
}

int bfs(int x,int y,int k)
{
    if(k>n) return 0;                           //n*n matrix����K�Σ��Լ�������ֵ�����
    if(matri[x][y]||n==1) return matri[x][y];   //����Ϊ0����ֻ��һ�������� 1*1 ���󣩣������
    int xx,yy,X,Y;
    int i,j;
    int cnt=0,die=0;
    for(i=0;i<4;i++)           //��������4���ߵ���������������ÿ��K��������д��
    {
        xx=x+k*cx[i];
        yy=y+k*cy[i];
        for(j=k;j--;)              //�൱��for(j=0;j<k;j++),һ��k��������������k��
        {
            if(in_matrix(xx,yy)&&matri[xx][yy])
            {
                if(cnt==1)
                {
                    die=1;
                    break;
                }

                X=xx;
                Y=yy;
                cnt++;

            }
            xx+=dx[i];
            yy+=dy[i];
        }
        if(die)
            break;
    }
    if(cnt==0)
        return bfs(x,y,k+1);
    else if(die)
        return 0;
    else
        return matri[X][Y];

}



int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            scanf("%d",&matri[i][j]);

    for(int i = 0; i < n; ++i,printf("\n"))
        for(int j = 0; j < n; ++j)
            printf("%d ",bfs(i,j,1));

    return 0;
}
