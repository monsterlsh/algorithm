#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
int num[210][210];
int n;
struct point
{
    int number;
    int mindis;
};
struct help
{
    int x,y;
    bool operator==(help a)
    {
        return a.x==x&&a.y==y;
    }
} ans[210][210];
point rem1[210][210];
void make(int i,int j,int k,int h)
{
     if(rem1[i][j].mindis==rem1[k][h].mindis+1)
     {
         if(rem1[i][j].number==1&&rem1[k][h].number==1&&ans[i][j]==ans[k][h])
            return;
        rem1[i][j].number+=rem1[k][h].number;
     }
            else if(rem1[i][j].mindis>rem1[k][h].mindis+1)
            {
                rem1[i][j].mindis=rem1[k][h].mindis+1;
                rem1[i][j].number=rem1[k][h].number;
                ans[i][j]=ans[k][h];
            }
}
int main()
{
   scanf("%d",&n);
   for(int i=0;i<=n+1;i++)
    for(int j=0;j<=n+1;j++)
    rem1[i][j].mindis=1000;
   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    scanf("%d",num[i]+j);

   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        if(num[i][j]>0){
        rem1[i][j].mindis=0;
        rem1[i][j].number=1;
        ans[i][j].x=i;
        ans[i][j].y=j;
        }
        else
        {
            make(i,j,i-1,j);
            make(i,j,i,j-1);
        }
    for(int i=n;i>=1;i--)
    for(int j=n;j>=1;j--)
        if(num[i][j]>0){
        rem1[i][j].mindis=0;
        rem1[i][j].number=1;
        ans[i][j].x=i;
        ans[i][j].y=j;
        }
        else
        {
            make(i,j,i+1,j);
            make(i,j,i,j+1);
        }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<n;j++)
          if(rem1[i][j].number==1)
            printf("%d ",num[ans[i][j].x][ans[i][j].y]);
          else
            printf("0 ");
        if(rem1[i][n].number==1)
            printf("%d\n",num[ans[i][n].x][ans[i][n].y]);
          else
             printf("0\n");
    }
    return 0;
}
