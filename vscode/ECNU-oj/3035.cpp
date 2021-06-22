/**
 * https://acm.ecnu.edu.cn/problem/3035/
 * 次大黑区域
 * 单点时限: 2.0 sec

内存限制: 256 MB

二值图像是由黑白两种像素组成的矩形点阵，图像识别的一个操作是求出图像中次大 (第二大) 黑区域的面积。请设计一个程序完成二值图像的这个操作。黑区域由若干黑像素组成，一个黑区域中的每个黑像素至少与该区域中的另一个黑像素相邻，规定一个像素仅与其上、下、左、右的像素相邻。两个不同的黑区域没有相邻的像素。一个黑区域的面积是其所包含的黑像素的个数。

输入格式
第 行：一个整数   为问题数。

接下来共  组测试数据，每组测试数据的第一行含两个整数  ，分别表示二值图像的行数与列数，后面紧跟着  行，每行含  个整数  或 ，其中第  行表示图像的第  行的  个像素， 表示白像素， 表示黑像素。同一行的相邻两个整数之间用一个空格隔开。

输出格式
对于每个问题，输出一行问题的编号（ 开始编号，格式：case #0: 等）。

然后对应每组测试数据，在一行中输出一个整数，表示相应的图像中次大（第二大）黑区域的面积。如果第二大面积的黑区域不存在时，则输出 。
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int figure[101][101];
int moves[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int black_hole(int n,int m);
void dfs(int i,int j,int n,int m,int &sum);

int black_hole(int n,int m){
    int sum=0;
    vector<int>res;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(figure[i][j]){
               
                dfs(i,j,n,m,sum);
                res.emplace_back(sum);
                // cout<<"sum: "<<sum<<" max:"<<max<<" second:"<<second<<endl;
            }
            sum=0;
            
        }
    }
    sort(res.begin(),res.end());
    int i=res.size()-1,x=1;
    sum = res[i];
    i--;
    while(i>=0){
        if(res[i]<sum){
            sum = res[i];
            x++;
            if(x==2)break;
        }
        i--;
    }
    x = i>=0?sum:0;
    return x;
}
void dfs(int i,int j,int n,int m,int &sum){
    if(i>=0&&j>=0&&i<n&&j<m&&figure[i][j]){
        figure[i][j]=0;
        sum++;
        for(int k=0;k<4;k++){
            dfs(i+moves[k][0],j+moves[k][1],n,m,sum);
        }
    }
}
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    scanf("%d",&t);
    int casenum = 0;
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&figure[i][j]);
            }
        }
        int second = black_hole(n,m);
        printf("case #%d:\n%d\n",casenum++,second);
    }
    return 0;
}