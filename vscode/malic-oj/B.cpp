
#include<iostream>
using namespace std;
int n;
string str = "ibti lbtlovebte lbtlibtinbtnkbtkebtezbas jebte dosadnbtna ovakbtkebtemibtijaxaszxdbtddbtddbtddbtddbtddbtd";

int main(){
    string zimu="linke";
    
    int n = str.length();
    int i=0;
    string res = "";
    while(i<n){
        res +=str[i++];
        for(int k=0;k<zimu.length();k++){
            if(zimu[k]==str[i-1]){
                i += 3;
                break;
            }
            
        }

    }
    cout<<res;
}

