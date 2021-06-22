#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int price[24];
int n;
string month;
int alls = 0;
struct dates
{
    vector<string> online, offline;
    vector<pair<string, string>> alltime;
    vector<double> xiaofei;
    double tolls;
};

void printmap(map<string, dates>::iterator &it);
void ssort(dates &it);
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    for (int i = 0; i < 24; i++)
    {
        cin >> price[i];
        alls += price[i] * 60;
    }
    cin >> n;
    map<string, dates> res;
    string names, datestr, on_offline;
    while (n--)
    {
        dates date;
        cin >> names >> datestr >> on_offline;
        month = datestr.substr(0, 2);
        datestr = datestr.substr(3, datestr.length() - 3);
        if (on_offline == "on-line")
            res[names].online.emplace_back(datestr);
        else
            res[names].offline.emplace_back(datestr);
    }
    map<string, dates>::iterator it = res.begin();
    for (; it != res.end(); it++)
    {
        ssort(it->second);
    }
    for (it = res.begin(); it != res.end(); it++)
    {
        printmap(it);
    }
}
void printmap(map<string, dates>::iterator &it)
{
    string name = it->first;
    dates x = it->second;
    cout << name << " " << month << endl;
    for (int i = 0; i < x.alltime.size(); i++)
    {
        cout << x.alltime[i].first << " " << x.alltime[i].second << " $" << x.xiaofei[i] << endl;
    }
    cout << "Total amount: $" << x.tolls / 100 << endl;
}
void ssort(dates &it)
{
    sort(it.online.begin(), it.online.end());
    sort(it.offline.begin(), it.offline.end());
    /*for(auto i : it.offline) cout<<i<<endl;
    cout<<"ss\n";*/

    int ion = 0, joff = 0;
    string first = it.online[ion], end;
    int dd1, hh1, mm1, dd2, hh2, mm2;
    int minus[24] = {0};
    //it.alltime.emplace_back(make_)
    while (ion < it.online.size() && joff < it.offline.size())
    {
        if (it.online[ion] < it.offline[joff])
            ion++;
        else
        {
            first = it.online[ion - 1];
            end = it.offline[joff];
            pair<string, string> a = {first, end};

            it.alltime.emplace_back(a);
            joff++;
        }
    }
    if (joff == it.offline.size() - 1)
    {
        first = it.online[ion - 1];
        end = it.offline[joff];
        pair<string, string> a = {first, end};
        it.alltime.emplace_back(a);
    }
    // for(auto i : it.alltime) cout<<i.first<<" " <<i.second<<endl;
    for (int i = 0; i < it.alltime.size(); i++)
    {
        fill(minus, minus + 24, 0);
        first = it.alltime[i].first;
        end = it.alltime[i].second;
        dd1 = stoi(first.substr(0, 2));
        hh1 = stoi(first.substr(3, 2));
        mm1 = stoi(first.substr(6, 2));
        dd2 = stoi(end.substr(0, 2));
        hh2 = stoi(end.substr(3, 2));
        mm2 = stoi(end.substr(6, 2));
        int d = hh2 - hh1, sum = 0;
        int j = hh1;
        int tominus = 0;
        if (d == 0)
        {

            if (hh1 == hh2)
            {
                sum += (mm2 - mm1) * price[hh1];
                tominus += mm2 - mm1;
            }
            else
            {
                for (j = hh1; j < hh2; j++)
                {
                    if (j == hh1)
                    {
                        sum += (60 - mm1) * price[j];
                        tominus += 60 - mm1;
                    }
                    else
                    {
                        sum += 60 * price[j];
                        tominus += 60;
                    }
                }
                tominus+=mm2;
                sum+=60*price[hh2];
            }
        }
        else {
            if (hh1 == hh2)
            {
                sum += (mm2 - mm1) * price[hh1];
                tominus += mm2 - mm1;
            }
        }
        if (d >= 0)
            sum += d * alls;
        it.xiaofei.emplace_back(sum * 1.0 / 100);
        it.tolls += sum * 1.0;
    }
}