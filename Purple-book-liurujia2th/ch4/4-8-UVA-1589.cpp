#include <iostream>
#include <cstring>
#include<vector>
using namespace std;
#define RE
typedef struct node{ 
    char name;
    size_t x,y;
};
char chessboard[11][10];
node reds[7];

size_t blackx,blacky,redx,redy,n,x,y;
char name;

//马位移
int horsePos[][2]={{-2,1},{-2,-1},
{2,1},{2,-1},
{1,2},{-1,2},{1,-2},{-1,-2}};
//上下左右 位移
int Pos[][2]={{-1,0},
{1,0},
{0,1},
{0,-1}};



bool notChess(char c){
    if(c=='R'||c=='C'||c=='H'){
        return false;
    }
    return true;
}

void setChess(bool flag){
    for(size_t i=0;i<11 && flag;i++)
        memset(chessboard[i],'0',sizeof(chessboard[i]));
    //chessboard[blackx][blacky]='B';
    for(size_t i=0;i<n;i++){
        node chess = reds[i];
        if(flag && chess.x==x && chess.y==y)continue ;
        chessboard[chess.x][chess.y]=chess.name;
    }
    for(size_t i=0;i<n;i++){
        node chess = reds[i];
        if(flag && chess.x==x && chess.y==y)continue ;
        switch (chess.name)
        {
        
        case 'R':
            if(chess.x<=3){
                for(size_t col=chess.y+1;col<=6 && notChess(chessboard[chess.x][col]) ;col++)
                        if(col>=4)
                        chessboard[chess.x][col]='1';
                for(size_t col=chess.y-1;col>=4 && notChess(chessboard[chess.x][col]);col--)
                        if(col<=6)
                        chessboard[chess.x][col]='1';
            }
             if(chess.y>=4 && chess.y<=6){
                for(size_t row=chess.x-1;row>=1 && notChess(chessboard[row][chess.y]);row--)
                    if(row<=3  )
                        chessboard[row][chess.y]='1';
                for(size_t row=chess.x+1;row<=3 && notChess(chessboard[row][chess.y]);row++)
                    if(row>=1)
                        chessboard[row][chess.y]='1';
            }
            break;
        case 'C':
        size_t col,row;
            for(col=chess.y+1;notChess(chessboard[chess.x][col])&&col<=6;col++);
            col++;
            for(;col<=6&&notChess(chessboard[chess.x][col]);col++)
                if(col>=4)chessboard[chess.x][col]='1';
            //left       
            for(col=chess.y-1;notChess(chessboard[chess.x][col])&&col>=4 ;col--);
            col--;
            for(;col>=4&&notChess(chessboard[chess.x][col]);col--)
                if(col<=6) chessboard[chess.x][col]='1';
            //up
            for( row=chess.x-1;notChess(chessboard[row][chess.y])&&row>=1;row--);
            row--;
            for(;row>=1 && notChess(chessboard[row][chess.y]);row--)
                if(row<=3) chessboard[row][chess.y]='1';
            //down
            for( row=chess.x+1;notChess(chessboard[row][chess.y])&&row<=3;row++);
            for(++row;row<=3;row++)
                if(notChess(chessboard[row][chess.y]))
                    chessboard[row][chess.y]='1';
        break;
        case 'H':
            
            //up
            if(chess.x-1>=1&& notChess(chessboard[chess.x-1][chess.y])){
                if(chess.x-2>=1 && chess.x-2<=3 && chess.y+1<=6 && chess.y+1>=4)
                chessboard[chess.x-2][chess.y+1]='1';
                 if(chess.x-2>=1 && chess.x-2<=3 && chess.y-1<=6 && chess.y-1>=4)
                 chessboard[chess.x-2][chess.y-1]='1';
            }
            //down
            if(chess.x+1<=10&& notChess(chessboard[chess.x+1][chess.y])){
                if(chess.x+2<=3  && chess.y+1<=6 && chess.y+1>=4)
                chessboard[chess.x+2][chess.y+1]='1';
                 if(chess.x+2<=3 && chess.y-1<=6 && chess.y-1>=4)
                 chessboard[chess.x+2][chess.y-1]='1';
            }
            //left
            if(chess.y-1>=1&& notChess(chessboard[chess.x][chess.y-1])){
                if(chess.y-2>=4 && chess.y-2<=6 && chess.x+1<=3 )
                chessboard[chess.x+1][chess.y-2]='1';
                 if(chess.y-2>=4 && chess.y-2<=6 && chess.x-1>=1 &&chess.x-1<=3 )
                 chessboard[chess.x-1][chess.y-2]='1';
            }
            //right
             if(chess.y+1<=9&& notChess(chessboard[chess.x][chess.y+1])){
                if(chess.y+2>=4 && chess.y+2<=6 && chess.x+1<=3 )
                chessboard[chess.x+1][chess.y+2]='1';
                 if(chess.y+2>=4 && chess.y+2<=6 && chess.x-1>=1 &&chess.x-1<=3 )
                 chessboard[chess.x-1][chess.y+2]='1';
            }
        break;
        }
    }
}
size_t kase=0;
void outGrap(){
    
    for(int i=1;i<=10;i++){
        for(int j=1;j<=9;j++)
            {
                if(i==blackx && j==blacky) cout<<" B"; else
                 printf(" %c",chessboard[i][j]);
            }
           
        cout<<endl;
    }
    cout<<endl;
}

//判断能否被将死 1 为活
bool judgeLive(){
    size_t i;
    for(i=redx-1; redy==y && notChess(chessboard[i][y])  && i>x;i--);
    if(i==x)return 0;
    if(chessboard[x][y]=='0')return 1;
    else if(chessboard[x][y]=='1')return 0; 
    return 1;
}
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
 
while(scanf("%zd%zd%zd",&n,&blackx,&blacky)==3 && blackx&&blacky&&n ){
    //printf("case %zd:\n",++kase);
    size_t i=0;
    
    getchar();
    memset(reds,0,sizeof(reds));
    
    for( i=0;i<n;i++){
        scanf("%c%zd%zd",&name, &x,&y);
        reds[i].name = name;
        reds[i].x = x;
        reds[i].y = y;
        if(name=='G'){
            redx=x;
            redy=y;
        }
        getchar();
    }
    bool flag = 0;

    //生成棋盘
    for(size_t i=0;i<11;i++)
        memset(chessboard[i],'0',sizeof(chessboard[i]));
    setChess(false);
    //BALCK
    
    //outGrap();
    if(redy==blacky){
        for(i=redx-1;i>blackx && notChess(chessboard[i][blacky]);i--);
        if(i==blackx)flag=1;
    }
    if(!flag)
    for( i=0;i<4;i++){
        x = Pos[i][0]+blackx;
        y = Pos[i][1]+blacky;
        if(x>=1&&x<=3 && y>=4&&y<=6){
            if(chessboard[x][y]=='R' || chessboard[x][y]=='C' ||chessboard[x][y]=='H' ){
                setChess(true);
                //此时棋盘把该xy去除
                if((flag=judgeLive())) break;
                //重新生成该 xy
                for(size_t i=0;i<11 && flag;i++)
                    memset(chessboard[i],'0',sizeof(chessboard[i]));
                setChess(false);
            }
            else  if((flag=judgeLive())) break;
        }
    }
    
    if(!flag)printf("YES\n");
    else printf("NO\n");

}
}
