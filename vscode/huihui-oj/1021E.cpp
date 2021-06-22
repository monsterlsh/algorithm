#include<iostream>
using namespace std;
bool chees[9][9]={0};
/*int movesright[8][2]={
    {1,2},{1,-2},{2,1},{2,-1}
};
int movesleft[4][2]={
    {-1,2},{-1,-2},{-2,1},{-2,-1}
};*/
int moves[8][2]={
    {1,2},{1,-2},{2,1},{2,-1}, {-1,2},{-1,-2},{-2,1},{-2,-1}
};
int mux,muy,maxs=999;
void backtrace(int  sum,int x,int y){
    if(x==mux && y==muy){if(maxs>sum)maxs=sum;return;}
    if(!chees[x][y] && x>=0 && y>=1 && x<8 && y<=8){
        chees[x][y]=1;
        sum++;
        //!!!!!!!!!!!!!!!!!!! 没有这句 ac50%
        if(sum>maxs){chees[x][y]=0;return;}
        for(auto next:moves){
            backtrace(sum,x+next[0],y+next[1]);
            if(sum>=maxs)break;
        }
        chees[x][y]=0;
    }
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    string str1,str2;
    while(cin>>str1>>str2){
        fill(chees[0],chees[0]+81,0);
        int x1=str1[0]-'a',x2=str1[1]-'0';
        int y1=str2[0]-'a',y2=str2[1]-'0';
        //chees[x1][x2]=1;
        //chees[y1][y2]=1;
        mux=y1;muy=y2;
        int sum=0;
        backtrace(sum,x1,x2);
        cout<<"To get from "<<str1<<" to "<<str2<<" takes "<<maxs<<" knight moves.\n";
        maxs=99999;
       // cout<<"\n\n";
    }
}