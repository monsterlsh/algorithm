#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, l, h;

struct node
{
    string id;
    int de;
    int cai;
    int score;
};
vector<node> stu;
bool first(const node &a, const node &b,bool less){
    return (a.score > b.score ? a.score > b.score : (a.score == b.score ? a.de > b.de : less));
}
bool second(const node &a, const node &b,bool less){
    return (a.score > b.score ? a.score > b.score : less);
}
bool third(const node &a, const node &b,bool less){
    return (a.score > b.score ? a.score > b.score : (a.score == b.score ? a.de > b.de : less));
}
bool last(const node &a, const node &b,bool less){
    return (a.score < b.score ? a.score < b.score : (a.score == b.score ? a.de > b.de : less));
}
bool cmp(const node &a, const node &b)
{
   // bool aScoreBigThenCScore = ;
   bool test;
    bool flag = (a.de >= h && a.cai >= h && first(a,b,false)) ||
                (a.de>=h && a.cai<h && b.de>=h && b.cai<h&& third(a,b,false)) ||
                ((test=(a.de >= h && a.cai >= h && b.de >= h && b.cai < h )&& second(a,b,test))) ||
                ((test=(a.de >= h && a.cai >= h && b.de < h ) && second(a,b,test))) ||
                (a.de<h && a.cai<h && b.de<h&&b.cai<h&&last(a,b,false) )||
               ((test=(a.de >= h && a.cai < h && b.de < h)) && second(a,b,test));
    return flag;
}
void proce()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    scanf("%d %d %d", &n, &l, &h);
    stu.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stu[i].id >> stu[i].de >> stu[i].cai;
        if (stu[i].de < l || stu[i].cai < l)
        {
            n--;
            i--;
            continue;
        }
        stu[i].score = stu[i].de + stu[i].cai;
    }
    stu.resize(n);
    sort(stu.begin(), stu.end(), cmp);
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << stu[i].id << "  " << stu[i].de << " " << stu[i].cai << " " << stu[i].score << endl;
    }
}
int main()
{
    proce();
}