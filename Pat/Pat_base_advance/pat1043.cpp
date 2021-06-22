#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main() {
    string ss,str="";
    getline(cin, ss);
    int p=0,a=0,T=0,e=0,s=0,t=0;
    for(int i=0;i<ss.length();i++){
        switch (ss[i])
        {
        case 'P':p++;break;
        case 'A':a++;break;
        case 'T':T++;break;
        case 't':t++;break;
        case 'e':e++;break;
        case 's':s++;break;
        default:
            break;
        }
    }
      while(p||a||T||e||s||t){
           if(p){str+="P";p--;}
           if(a){str+="A";a--;}
           if(T){str+="T";T--;}
           if(e){str+="e";e--;}
           if(s){str+="s";s--;}
           if(t){str+="t";t--;}
        }
        cout<<str<<endl;
    return 0;
}