#include<iostream>
#include<vector>
using namespace std;
int n;
int maps[21];
 int case_index=1;
bool isprime(int m){
    if(m<2)return false;
    for(int i=2;i*i<=m;i++){
        if(m%i==0)return false;
    }
    return true;
}
void dfs(int step,vector<int>&res)//深搜1到n的全排列。 
{
	int i;
	if(step == n)
	{
		res.emplace_back(res[0]);
		for(i=0;i<n;i++)
		{
			if(!isprime(res[i]+res[i+1])){
				//来判断条件不是不是满足 
				res.pop_back();
				return ;
				}
		}
		for(i=0; i<n; i++)
			printf("%d%c", res[i],i==n-1?'\n':' ');//输出满足条件的序列 
		res.pop_back();
	}
	else 
	for(i=2; i<=n; i++)//深搜的核心代码。 
	{
		if(!maps[i])
		{
			//cout<<i<<" "<<endl;
			res.emplace_back(i);
			maps[i]=1;
			dfs(step+1,res);
			maps[i]=0;
			res.pop_back();
		}
	}
	
}



int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
  
   
    while (scanf("%d",&n)!=EOF)
    {
		fill(maps,maps+21,0);
		vector<int>res;
		res.emplace_back(1);
		maps[1]=1;
		printf("Case %d:\n",case_index++);
        dfs(1,res);
		cout<<endl;
        
    }
    
}
