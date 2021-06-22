#include <cstdio>
#include <iostream>
#include <vector>
#include<cstring>
#include <algorithm>

using namespace std;
char ans[201];
int main(){
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    	char str[210];
	while(gets(str)!=NULL){
		int len=strlen(str);
		sort(str,str+len);
		puts(str);
	}
	return 0;
}