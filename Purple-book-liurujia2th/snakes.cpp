/*
蛇形填数。在n×n方阵里填入1，2，…，n×n，要求填成蛇形。例如，n＝4时方阵为：
10 11 12 1
9 16 13 2
8 15 14 3
7 6 5 4
上面的方阵中，多余的空格只是为了便于观察规律，不必严格输出。n≤8。
*/
#include<iostream>
#include<vector>
using namespace std;
int main(){
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    unsigned n;
    while(scanf("%u",&n)!=EOF){
        vector<vector<unsigned long long>> res(n,vector<unsigned long long>(n,0));
        int down=n-1,left=0,up=0,right=n-1,y=0,i;
        unsigned long long sum=1;
        unsigned long long fin = n*n;
        
        while(sum<=fin){
            for(i=up;i<=down && sum<=fin;i++) res[i][right]=sum++;
            for(i=right-1;i>=left && sum<=fin;i--)res[down][i]=sum++;
            for(i=down-1;i>=up && sum<=fin;i--)res[i][left] = sum++;
            for(i=left+1;i<=right-1 && sum<=fin;i++)res[up][i]=sum++;
            down--;left++;up++;right--;
        }
        for(i=0;i<n;i++){
            for(int j=0;j<n;j++)
                printf("%-10llu ",res[i][j]);
            cout<<endl;
        }
    cout<<endl;
    }
}