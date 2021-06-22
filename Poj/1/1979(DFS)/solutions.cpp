#include <stdio.h>
#define MAX_H 20

int map[MAX_H][MAX_H];
int visited[MAX_H][MAX_H];
int height;
int width;
int resultCount = 0;
int arr[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; //right down left up

int dfs(int x, int y);
int main()
{
      //freopen("input.txt","r",stdin);
      int i = 0;
      int j = 0;
      char tempChar;
      scanf("%d %d",&width,&height);
      int startWidth = 0;
      int startHeight = 0;
      while(!(width==0 && height==0))
      {
            resultCount = 1;
            for(i=0;i<height;i++)
            {
                  for(j=0;j<width;j++)
                  {
                      visited[i][j] = 0;
                      scanf(" %c",&tempChar);
                      if(tempChar=='.')
                      {
                             map[i][j] = 0;
                      }
                      else if(tempChar=='#')
                      {
                             map[i][j] = 1;
                      }
                      else if(tempChar=='@')
                      {
                             map[i][j] = 2;
                             startWidth = j;
                             startHeight = i;
                      }
              }
        }

        dfs(startHeight,startWidth);

        printf("%d\n",resultCount);

        scanf(" %d %d",&width,&height);
    }


    return 0;
}


int dfs(int x, int y)
{
       int i = 0;
       int tempx = 0;
       int tempy = 0;
       for(i=0;i<4;i++)
       {
              tempx = x + arr[i][0];
              tempy = y + arr[i][1];
              if(tempx>=0 && tempx<height && tempy>=0 && tempy<width)
              {
                       if(map[tempx][tempy]==0 && visited[tempx][tempy]==0)
                       {
                                visited[tempx][tempy] = 1;

                                resultCount++;

                                dfs(tempx,tempy);

                       }
              }

       }
       return 0;
}
