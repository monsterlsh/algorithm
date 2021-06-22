#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
    int n=0 ;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
      int num=0;
	  scanf("%d",&num);
      if (num == 1) {
      	printf("%d\n",1);
      } else {
        num = (num - 1) << 1;
        int use = sqrt(num);
        if (use * (use + 1) == num) {
        	printf("%d\n",1);
        } else {
        	printf("%d\n",0);
        }
      }
    }
 } 