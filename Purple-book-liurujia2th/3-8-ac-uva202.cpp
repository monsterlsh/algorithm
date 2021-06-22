#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
 #define RE
int a, b;
int hash_table[30010]; // 用来统计余数出现的位置，若余数出现过，则表示开始循环了
vector<int> ans; // 拿来保存小数部分
int main()
{
#ifdef RE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
   while (scanf("%d %d", &a, &b) != EOF) {
        ans.clear();
        memset(hash_table, -1, sizeof(hash_table));
        int num = a / b; // 整数
        int re = a % b; // 余数
        hash_table[re] = 0;
        int cnt = 0; // 小数部分的个数
        re *= 10;
        printf("%d/%d = %d.", a, b, num);
        while (1) {
            a = re / b; // 新的商
            ans.push_back(a);
            re = re % b; // 新的余数
            //printf("shang=%d,yu=%d\n", a, re);
            cnt++;

            if (hash_table[re] != -1) {
                // 重复了,开始输出,只输出50位小数
                int point = 0;
                for (int i = 0; i < hash_table[re]; point++,i++) printf("%d", ans[i]);
                printf("(");
                for(int i=hash_table[re];i<cnt && point < 50;point++,i++) printf("%d", ans[i]);
                if (point == 50) printf("...");
                printf(")\n");
                printf("   %d = number of digits in repeating cycle\n\n", cnt - hash_table[re]);
                break;
            }
            else {
                hash_table[re] = cnt;
                re *= 10; // 继续计算
            }
        }
    }
    return 0;
}
