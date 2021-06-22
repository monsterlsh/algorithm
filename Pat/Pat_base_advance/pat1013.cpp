#include <iostream>
#include <vector>
using namespace std;

//vector<int> arr(1000);
bool judge(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void test1()
{
    freopen("input.in", "r", stdin);
    int m, n;
    cin >> m >> n;
    int  cnt = 0;
    if (m % 2 == 0)
        m++;
    for (; m <= n; m += 2)
    {
        if (judge(m))
        {
            cnt++;
            cout << (cnt % 10 == 1 ? "" : " ") << m;
            if (cnt % 10 == 0)
                cout << endl;
        }
    }
    if (cnt % 10 != 0)
        cout << endl;
}
void dabiao( int M, int N)
{

    int  num = 3, cnt = 1;
    if (M == 1 && N!=M)cout<<2;
    else if(M==1&&N==M){
        cout<<2<<endl;
        return;
    }
    while (true)
    {
        if (judge(num))
        {
            cnt++;
            if (cnt>=M)
            cout << ((cnt-M+1 )% 10 == 1 ? "" :" " ) << num << ((-M+cnt+1 )%10==0?"\n":"");
            if (cnt == N)
            {
                if ((cnt-M+1) % 10 != 0)
                    cout << endl;
                break;
            }
        }
        num += 2;
    }
}
int main()
{
    int m,n;
    cin>>m>>n;
    dabiao(m,n);
}