#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
char arr [101][101];
using namespace std;
int main(){
    int n;

    while(cin>>n && n != 0){
            memset(arr,0,sizeof(arr));
        int len = 2*n-1;
        streambuf * backup;
        ifstream fin;
        ofstream fout;
        fin.open("data.txt");
        backup = cin.rdbuf();
        cin.rdbuf(fin.rdbuf());
     int ilen,jlen,dis;
        for(int i = 1;i<=n;i++){
                ilen = (n - i + 1);
                jlen = 2*ilen-1;
                dis = (len - jlen)/2;
            for(int j = dis+1 ;j<=(len-dis);j++) {
                cin>>arr[i][j];
                cout<< arr[i][j];
            }
            cout <<endl;
        }

        cin.rdbuf(backup);
        fin.close();
         //test
    /* for(int i = 1;i<=n;i--){
                 ilen = (n - i + 1);
                 jlen = 2*ilen-1;
                 dis = (len - jlen)/2;
            for(int j = len - dis ;j>=dis+1;j--){
                cout << arr[i][j];
        }
    cout << endl;
     }*/
    //test

    }

}
