#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string weeks[8] = { "MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
string str = "";
//wrong
void pro()
{
    string a, b;
    cin >> a >> b;
    size_t mins = 70,secmin=71;
    //int week = -1,time=-1;
    char tmp=' ',sectmp=tmp;
    for (size_t i = 0; i < a.size(); i++)
    {
        if(!isupper(a[i]))continue;
        auto pos = b.find_first_of(move(a.substr(i, 1)), 0);
        if(pos==string::npos)continue;
        mins = min(min(pos, i), mins);
        if(mins!=70) secmin=max(min(min(pos, i), secmin),mins);
        tmp = mins<i?b[mins]:a[mins];
        sectmp = secmin<i?b[secmin]:a[secmin];
    }
    str += weeks[(tmp-'A')%7] + to_string((isdigit(sectmp)? sectmp-'0':sectmp-'A'+11))+":" ;
    cin>>a>>b;
    for (size_t i = 0; i < a.size(); i++){
        if(!isalpha(a[i]))continue;
        auto pos = b.find_first_of(move(a.substr(i, 1)), 0);
        if(pos==string::npos)continue;
        a = i>pos?to_string(i):to_string(pos);
        str += mins<9?"0"+a:a;
        break;
    }
    cout<<str<<endl;
}
//right
void liunuo(){
     string a, b, c, d;
    cin >> a >> b >> c >> d;
    char t[2];
    int pos, i = 0, j = 0;
    while(i < a.length() && i < b.length()) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            t[0] = a[i];
            break;
        }
        i++;
    }
    i = i + 1;
    while (i < a.length() && i < b.length()) {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))) {
            t[1] = a[i];
            break;
        }
        i++;
    }
    while (j < c.length() && j < d.length()) {
        if (c[j] == d[j] && isalpha(c[j])) {
            pos = j;
            break;
        }
        j++;
    }
    string week[7] = {"MON ", "TUE ", "WED ", "THU ", "FRI ", "SAT ", "SUN "};
    int m = isdigit(t[1]) ? t[1] - '0' : t[1] - 'A' + 10;
    cout << week[t[0]-'A'];
    printf("%02d:%02d", m, pos);
}
int main(){
    liunuo();
}