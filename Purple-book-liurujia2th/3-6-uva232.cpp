#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 10
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    size_t row,col,kase=0;
    //如果边输入边打印呢？can wa？
    while(scanf("%zd%zd",&row,&col)!=EOF && row && col ){
        
        getchar();
        vector<string>grid(row),rows,cols;
        rows.emplace_back("");
        size_t i=0;char c=' ';
        for(;i<row;i++){
            //size_t n=0;
            for(int j=0;j<col;j++){
                //if(i==0 || !(i!=0 && j==0))
                c=getchar();
                if(i==0) cols.emplace_back("");
                if(i==0) cols[cols.size()-1].push_back(c);
                else cols[j].push_back(c);
               // grid[i][j] += c;
                if(c!='*'){
                    rows[rows.size()-1].push_back(c);
                }else if(!(i==row-1&&j==col-1) &&!rows[rows.size()-1].empty())rows.emplace_back("");
            }
            getchar();
            //while((!isalpha(c=getchar())||c!='*'));
            if(i!=row-1&&!rows[rows.size()-1].empty())rows.emplace_back("");
        }//build grid and ready to put row
        //output row
        size_t num=0;
        printf("puzzle #%zd:\nAcross\n",++kase);
        for(string s:rows)
        printf("  %zd.%s\n",++num,s.c_str());
        //output col
        kase=0;
        printf("Down\n");

    }
}
