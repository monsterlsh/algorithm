#include<iostream>
using namespace std;
int main()
{
 int k,i,j,min,are,q,n;
 cin>>q;
 while(q--)
 {
  cin>>n;
  min=10000000;
  for(i=1;i<=n;i++)
  {
   for(j=1;j*i<=n;j++)
   {
    if(n%(i*j)==0)
    {
     k=n/i/j;
     are=2*(i*j+i*k+j*k);
     if(are<min) min=are;
    }
   }
  }
  cout<<min<<endl;
 }
 return 0;
}
