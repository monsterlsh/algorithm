#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;
int D[MAX][MAX];
int n;
int maxsum[MAX][MAX];
int Maxsum(int i,int j){
    if(maxsum[i][j]!=0) return maxsum[i][j];
    if(i==n) return D[i][j];

    else{
        int max1 = max(Maxsum(i+1,j),Maxsum(i+1,j+1));
        maxsum[i][j] = max1 + D[i][j];
        return max1 + D[i][j];
    }
}
int main(){
     int i,j;
    cin >> n;
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
        {
            cin >> D[i][j];
            maxsum[i][j]=0;
        }

    cout << Maxsum(1,1) << endl;
}
