#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    string str;
    /*��ͬ��stringͷ�ļ���һ����֧��getline(cin,string);
    char a[100];
    cin>>a;
    cout<<a<<endl;*/
    streambuf * backup;
    ifstream fin;
    ofstream fout;
   /* fout.open("data.txt");
    backup = cout.rdbuf();
    cout.rdbuf(fout.rdbuf());
    //cin>>str;    /*�пո�ͻ�ֹͣ*/
   // getline(cin, str);    /*ֱ�����з�����ֹͣ*/
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
