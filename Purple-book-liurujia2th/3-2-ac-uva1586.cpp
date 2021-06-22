#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
double f(char x)
{
    switch(x)
    {
        case 'C': return 12.01;
        case 'H': return 1.008;
        case 'O': return 16.00;
        case 'N': return 14.01;
    }
}

int main(void)
{
    string str;
    int T, p;
    cin>>T;
    while(T--)
    {
        double ans = 0;
        cin>>str;
        for(int i = 0; i < str.length(); i++)
        {
            if (isalpha(str[i]))
            {
                if (isdigit(str[i+1]) && isdigit(str[i+2])) p=(str[i+1]-'0')*10+str[i+2]-'0';
                else if (isdigit(str[i+1])) p=str[i+1]-'0';
                else p=1;
                ans+=f(str[i])*p;
            }
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}