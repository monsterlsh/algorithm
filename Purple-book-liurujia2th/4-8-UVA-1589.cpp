#include <iostream>
#include <cstring>
#include<vector>
using namespace std;
#define RE
typedef struct node{ 
    char name;
    size_t x,y;
};
//const node emp={' ',0,0};
node chessboard[11][10];
node reds[7];
const char chariot='R',general='G',horse='H',cannon='C';

size_t blackx,blacky,n,name,x,y;

int position[][2]={{-2,1},{-2,-1},{2,1},{2,-1}};


void judge(){
    
}
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
 
while(scanf("%zd%zd%zd",&n,&blackx,&blacky)==3 && blackx&&blacky&&n ){
    size_t i=0;
    
    getchar();
    memset(reds,0,sizeof(reds));
    for( i=0;i<n;i++){
        scanf("%c%zd%zd",&name, &x,&y);
        chessboard[x][y]=reds[i];
        getchar();
    }
    judge();
}
}
