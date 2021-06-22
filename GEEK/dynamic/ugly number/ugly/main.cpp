#include <iostream>

using namespace std;

int main()
{
   int t,n;
   cin>>t;
   while(t--)
   {
       cin>>n;
       int i = 0;
       for(int j = 1; ;j++)
       {

           if(j%2==0 || j%3==0 || j%5==0 || j==1) i++;
            if(n==i)
           {
               cout << j;
               break;
           }
       }
   }
    return 0;
}
