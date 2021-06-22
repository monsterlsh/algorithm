#include<stdio.h>

int main() {
	int n, a[100], k;
	while(scanf("%d",&n) != EOF){
		while(n > 0) {
			n--;
			scanf("%d", &k);
			for(int i = 0; i < k; i++)
				scanf("%d", &a[i]);
			if(a[0] != a[1])
				printf("0 ");
			for(int i = 1; i < k-1; i++)
				if((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] < a[i + 1]))
					printf("%d ", i);    
			if(a[k - 2] != a[k - 1])   
				printf("%d\n", k - 1);
		}
	}
	return 0;
}
