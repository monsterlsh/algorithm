#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int n, m;
struct node
{
    string str;
    int score;
} nodes[10001];
// B123 180908 127 99
vector<node> A;
vector<node> B;
vector<node> C;
//2
struct node2
{
    int nums;
    int scores;
} sites[1001];

//3
map<string, vector<pair<int, int>>> ss3;

void f1(int n, int index)
{
    char ch;
    cin >> ch;
    //vector<int>res;
    printf("Case %d: %d %c\n", index, n, ch);
    switch (ch)
    {
    case 'A':
        if(A.size()==0){
            cout<<"NA\n";
            break;
        }
        for (auto x : A)
        {
            cout << x.str << " " << x.score << endl;
        }
        break;
    case 'B':
    if(B.size()==0){
            cout<<"NA\n";
            break;
        }
        for (auto x : B)
        {
            cout << x.str << " " << x.score << endl;
        }
        break;
    case 'C':
        if(C.size()==0){
            cout<<"NA\n";
            break;
        }
        for (auto x : C)
        {
            cout << x.str << " " << x.score << endl;
        }
        break;
    }
}

void f2(int n, int i)
{
    int index;
    cin >> index;
    printf("Case %d: %d %d\n", i, n, index);
    if(sites[index].nums==0 )cout<<"NA\n";
    else cout << sites[index].nums << " " << sites[index].scores << endl;
}
void f3(int n, int index)
{
    string str;
    cin >> str;
    printf("Case %d: %d ", index, n);
    cout << str << endl;
    if(ss3[str].size()==0) cout<<"NA\n";
    for (int i = 0; i < ss3[str].size(); i++)
    {
        cout << ss3[str][i].first << " " << ss3[str][i].second << endl;
    }
}

void sorta(vector<node> & s)
{
    sort(s.begin(), s.end(), [](const node &a, const node &b) {
        if (a.score == b.score)
        {
            return a.str < b.str;
        }
        return a.score > b.score;
    });
}
void sortss3(vector<pair<int, int>> &s)
{
    sort(s.begin(), s.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second > b.second;
    });
}
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i].str >> nodes[i].score;
        switch (nodes[i].str[0])
        {
        case 'A':
            A.push_back(nodes[i]);
            break;
        case 'B':
            B.push_back(nodes[i]);
            break;
        case 'C':
            C.push_back(nodes[i]);
            break;
        }
        //2
        int index = stoi(nodes[i].str.substr(1, 3));
        sites[index].nums++;
        sites[index].scores += nodes[i].score;
        //3
        string date = nodes[i].str.substr(4, 6);

        if (ss3.find(date) != ss3.end())
        {

            /*for (map<string, vector<pair<int, int>>>::iterator it = ss3.begin(); it != ss3.end(); it++)
            {
               for(auto x:it->second){
                   if(x.first==index) x.second++;
               }
            }*/
            bool flag = true;
            for(int i=0;i<ss3[date].size();i++){
                   if(ss3[date][i].first==index) {ss3[date][i].second++;flag=false;break;}
               }
            if(flag){
                ss3[date].emplace_back(make_pair(index, 1));
            }
        }
        else
        {
            vector<pair<int, int>> tmp;
            tmp.emplace_back(make_pair(index, 1));
            ss3[date] = tmp;
        }
    }
    //1: 排序A b c
    /* cout<<"test be"<<endl;
    for(auto i:A){
       
        cout<<i.str<<" "<<i.score<<endl;
       
    }
     cout<<"test en"<<endl;*/
    sorta(A);
    sorta(B);
    sorta(C);
    //2:
    //3
    for (map<string, vector<pair<int, int>>>::iterator it = ss3.begin(); it != ss3.end(); it++)
    {
        sortss3(it->second);
    }

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;

        switch (num)
        {
        case 1:
            f1(num, i + 1);
            break;
        case 2:
            f2(num, i + 1);
            break;
        case 3:
            f3(num, i + 1);
            break;
        }
    }
}
