/*
ID: uplshup1
TASK: gift1
LANG: C++
*/
#include <iostream>
#include<fstream>
#include<map>

using namespace std;
string allnames[15];
bool cmp(pair<int,int> & a,pair<int,int> & b)
{
    return a.first<b.first;
}
int main(){
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
  int T;
  fin>>T;
  map<string,int>members;
  int na = 0,all = T;
  while(T--)
  {
      string name;
      fin>>name;
      allnames[na++] = name;
      members.insert(make_pair(name,0));
  }
  while(1)
  {
      string name;
      fin>>name ;
      if(fin.eof()) break;
      int money,np;
      fin>>money>>np;
      if(money == 0)
      {
          while(np--)
          {
              fin>>name;
          }
          continue;
      }
      else if(np == 0) continue;
      int assign = money/np;
      int remain = money%np;
      members[name] =  members[name]-money + remain;
      while(np--)
      {
          string given_name;
          fin>>given_name;
          members[given_name] += assign;
      }
  }
  for(int i = 0; i<all;i++)
    fout<<allnames[i]<<" "<<members[allnames[i]]<<endl;


  return 0;
}
