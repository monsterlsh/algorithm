/*
ID: uplshup1
TASK: largeset prime factor
LANG: C++
TIME: 2019年3月18日21:23:45
*/
/*
* 参考别人的
*/

#include <iostream>
#include <cstdio>
 
 
using namespace std;
 
const int maxn = 1000005;
int biao[maxn];
 
/**
 * 求一个数的最大质因子的位置。如2的位置是1。
 * 3的位置是2
 */
void prepare(){
	int i;
	int k = 1;
	for(i = 2 ; i < maxn ; ++i){//遍历数据范围内的所有数
		if(biao[i] == 0){//如果这一个数的最大质因子的位置还没有确定
			int j;
			for(j = 1 ; i*j < maxn ; ++j){//把含有这个质因子的所有数的位置都标记成这个质因子的位置
				biao[i*j] = k;
			}
			k++;//质因子的位置索引+1
		}
	}
}
 
 
int main(){
	int n;
	prepare();
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",biao[n]);//biao[n]表示n的最大质因子的位置
	}
 
	return 0;
}
