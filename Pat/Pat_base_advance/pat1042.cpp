
#include <iostream>
#include<cctype>
using namespace std;
int main() {
    int max = -1;char mini='z';
    string str;
    char ch;
    cin>>str;
    int i=0;
    int list[26];
    //哪里不对？
    while(i<str.length()){
        ch = str[i];
        if(isalpha(ch)){
            if(isupper(ch)) ch = tolower(ch);
            list[ch-'a']++;
          
        }
        i++;
    }
    i = 0;
    while(i<str.length()){
        if(str[i]>max){
            mini = i+'a';
            max = str[i];
        }
        i++;
    }
    cout<<mini<<" "<<max;
}