/**
 * 1037 在霍格沃茨找零钱 (20 分)
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 
就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”
现在，给定哈利应付的价钱 P 和他实付的钱 A，你的任务是写一个程序来计算他应该被找的零钱。*/
#include <iostream>
using namespace std;
int main() {
    int a, b ,c, m, n, t, x, y, z;
    scanf("%d.%d.%d %d.%d.%d",&a, &b, &c, &m, &n, &t);
    if (a > m || (a == m && b > n) || (a == m && b == n && c > t)) {
        swap(a, m); swap(b, n); swap(c, t);
        printf("-");        
    }
    z = t < c ? t - c + 29 : t - c;
    n = t < c ? n - 1 : n;
    y = n < b ? n - b + 17 : n - b;
    x = n < b ? m - a - 1 : m - a;
    printf("%d.%d.%d", x, y, z);
    return 0;
}