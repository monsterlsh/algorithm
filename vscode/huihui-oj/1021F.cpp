#include <iostream>
using namespace std;
char maps[21][21];

int h, w;
int moves[4][2]={
    {1,0},{0,1},{-1,0},{0,-1}
};

void dfs(int x,int y,int &sum){
    if(x>=0&&x<h&&y>=0&&y<w && maps[x][y]!='#'){
      //  cout<<"x:"<<x<<" y:"<<y<<endl;
        maps[x][y]='#';
        sum++;
        //cout<<sum<<" ";
        for(auto next:moves){
            dfs(x+next[0],y+next[1],sum);
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while (cin >> w >> h && h && w)
    {
        int x, y;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> maps[i][j];
                if (maps[i][j] == '@'){
                    x = i;
                    y = j;
                    //cout<<"i,j="<<i<<" "<<j<<endl;
                }
            }
        }
        int sum=0;
        dfs(x,y,sum);
        cout<<sum<<endl;
    }
}