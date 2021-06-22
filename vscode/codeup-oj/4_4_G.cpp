// http://codeup.hustoj.com/problem.php?cid=100000584&pid=6
#include <cstdio>
int money[5]={50,20,10,5,1};
int main(){
	int m,i,x;
	while(scanf("%d",&m)!=EOF){
		for(i=0;i<5;i++){
			x=m/money[i];
			if(x){
				printf("%d*%d",money[i],x);
				m%=money[i];
				if(m){
					printf("+");
				}
			}
		} 
		printf("\n");
	}
	return 0;
}