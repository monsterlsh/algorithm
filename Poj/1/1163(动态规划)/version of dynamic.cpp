#include <iostream>
#include <algorithm>
#include<fstream>
#define MAX 101
using namespace std;
int D[MAX][MAX];
int n;
int maxsum[MAX][MAX];
int main(){
  int i,j;

ifstream in("data.txt");

if(in.is_open())
{
    while(!in.eof())
    {
        in >> n;
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
        {
            in >> D[i][j];
        }


        in.close();
    }
}

    //cin.rdbuf(backup);
   for(i=n-1;i>=1;i--)
   for(j=1;j<=i;j++){
        int max1 = max(D[i+1][j],D[i+1][j+1]);
    D[i][j]= D[i][j] + max1;
   // cout<<"D[" << i << "]["<< j << "] = " << D[i][j] <<endl;
   cout << D[1][1] <<endl;

}

}
/*
AC:

    #include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101

int D[MAX][MAX];
int n;
int maxSum[MAX][MAX];
int main(){
    int i,j;
    cin >> n;
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
            cin >> D[i][j];
    for( int i = 1;i <= n; ++ i )
        maxSum[n][i] = D[n][i];
    for( int i = n-1; i>= 1;  --i )
        for( int j = 1; j <= i; ++j )
            maxSum[i][j] = max(maxSum[i+1][j],maxSum[i+1][j+1]) + D[i][j];
    cout << maxSum[1][1] << endl;
}
*/
