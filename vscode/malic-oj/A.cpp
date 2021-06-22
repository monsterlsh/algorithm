#include<cstdio>
int main() {
    char c1;
    int n = 26; //设定塔的层数为26
    int i, j;
    for (i = 1; i <= n; i++) {   //对塔每一层按照规律进行构造。
        //首先进行输出空格的操作：对于第i行，字符前面的空格个数为n-i个。
        for (j = 1; j <=(n-i); j++)
            printf(" ");
        for (j = 1; j <= i; j++) { //按照规律1，输出第1~第i个大写字母。
            c1 = j + 'A' - 1; //第j个大写字母为'A'+j-1
            printf("%c", c1); //输出第j个大写字母
        }
        for (j = i-1; j >= 1; j--) {//按照规律1，输出第i-1~第1个大写字母，注意是倒序
            c1 = j+'A'-1;
            printf("%c", c1);
        }
        printf("\n");//第i行输出结束，进行换行。
    }
    return 0;
}