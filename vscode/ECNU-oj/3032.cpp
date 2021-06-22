#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>num;
vector<int>nexts(5001);
int maxs=1;
bool flagnum = true;
void fn();

void fn()
{
    int dex = 2, sum = 0;
    for(int i=0;dex*i+1<=10000;i++){
        num.emplace_back(dex*i+1);
    }
    maxs=num.size();
    
    while(dex<=maxs){
        if(flagnum){
            flagnum = 0;
            int i=0,j=0;
            for(;i<maxs;i++){
                if(sum==dex){sum=0;}
                else {
                    nexts[j++] = num[i];
                    sum++;
                }
            }
            maxs=j;
            dex++;
            sum=0;
            /*cout<<"nexts:\n";
            for(i=0;i<maxs;i++){
                cout<<nexts[i]<<" ";
            }
            cout<<endl;*/
        }
        if(!flagnum){
            flagnum = 1;
            int j =0;
            for(int i=0;i<maxs;i++){
                if(sum==dex){sum=0;}
                else {
                    num[j++] = nexts[i];
                    sum++;
                }
            }
            maxs=j;
            dex++;
            sum=0;
            /*cout<<"num:\n";
            for(int i=0;i<maxs;i++){
                cout<<num[i]<<" ";
            }
            cout<<endl;*/
        }
    }
   
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int t;
    scanf("%d", &t);
    fn();
    int casenum = 0;
    vector<int>res;
    while (t--)
    {
        int n;
        scanf("%d",&n);
        int i=0;
        for(;i<maxs;i++){
            if(flagnum && num[i]==n)break;
            if(!flagnum && nexts[i]==n)break;
        }
        printf("case #%d:\n", casenum++);
        if(i==maxs) printf("No\n");
        else printf("Yes %d\n",i+1);
    }
    return 0;
}