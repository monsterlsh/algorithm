#include <iostream>
using namespace std;
int ex = 1;
long long a1 = 0, a2 = 0;int num4=0, a3 = 0, a5 = -1;
double a4=0.0;
bool flag=false;
int main()
{
    int n;
    freopen("input.in", "r", stdin);
    scanf("%d", &n);
    while (scanf("%d", &n) != EOF)
    {
        int x = n % 5;
        switch (x)
        {
        case 0:
            if(n%2==0)a1+=n;
            break;
        case 1:
            flag=true;
            a2 += n*ex;
            ex*=-1;
            break;
        case 2:
            a3++;
            break;
        case 3:
            num4++;
            a4+= n;
            break;
        case 4:
            if(n>a5)a5=n;
            break;
        }
    }
    if(a1==0) cout<<"N ";
    else cout<<a1<<" ";
    if(!flag) cout<<"N ";
     else cout<<a2<<" ";
    if(a3==0) cout<<"N ";
     else cout<<a3<<" ";
    if(a4==0) cout<<"N ";
     else printf("%.1lf ",a4/num4);
    if(a5==-1) cout<<"N\n";
     else cout<<a5<<"\n";


}