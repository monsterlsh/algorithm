#include<stdio.h>
#include<math.h>

int main()
{
    int i,n;
    float pi,x,y,years;
    scanf("%d", &n);
    pi = acos(-1);

    for(i=1; i<=n; i++)
    {
        scanf("%f%f",&x,&y);

        years = pi*(x*x + y*y)/100;

        printf("Property %d: This property will begin eroding in year %d.\n",i,(int)years+1);
    }
    printf("END OF OUTPUT.\n");

    return 0;
}
