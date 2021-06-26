#include <stdio.h>
#include<iostream>
using namespace std;
 #define RE
char s[12][12];
int num[12][12], row, col;

void print(int x, int y, int flag) {
    printf("%3d.", num[x][y]);
    if(flag) {
        for(int j=y;;j++) {
            if(j>=col || s[x][j]=='*') break;
            putchar(s[x][j]);
        }
    }
    else {
        for(int i=x;;i++) {
            if(i>=row || s[i][y]=='*') break;
            putchar(s[i][y]);
        }
    }
    putchar('\n');
}

int main() {
#ifdef RE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
    int kcase=0;
    while(scanf("%d%d\n", &row, &col)==2 && row && col) {
        int number=0;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                s[i][j]= getchar();
                //cout<< s[i][j]<<"++"<<endl;
                if(s[i][j] == '*') continue;
                if(!i || !j || s[i-1][j]=='*' || s[i][j-1]=='*') num[i][j]=++number;
            }
            getchar();
        }

        if(kcase) printf("\n");
        printf("puzzle #%d:\nAcross\n", ++kcase);
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(s[i][j] != '*' && (!j || s[i][j-1]=='*')) print(i, j, 1);
        printf("Down\n");
        for(int i=0; i<row; i++) 
            for(int j=0; j<col; j++) 
                if(s[i][j] != '*' && (!i || s[i-1][j]=='*')) print(i, j, 0);
    }
    return 0;
}