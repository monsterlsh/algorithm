#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    string str;
    /*不同的string头文件不一定都支持getline(cin,string);
    char a[100];
    cin>>a;
    cout<<a<<endl;*/
    streambuf * backup;
    ifstream fin;
    ofstream fout;
   /* fout.open("data.txt");
    backup = cout.rdbuf();
    cout.rdbuf(fout.rdbuf());
    //cin>>str;    /*有空格就会停止*/
   // getline(cin, str);    /*直到换行符处才停止*/
   /* cout<<str<<endl;
    cout.rdbuf(backup);
    fout.close();*/
char ch;
    //str.clear();
    fin.open("data.txt");
    backup = cin.rdbuf();
    cin.rdbuf(fin.rdbuf());

    cin>>ch;
    cout<<ch<<'!'<<endl;
    cin>>ch;
    cout<<ch<<'!'<<endl;
    cin.rdbuf(backup);

    fin.close();
    return 0;
}
