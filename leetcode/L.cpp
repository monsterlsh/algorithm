#include <iostream>
#include<cctype>
#include<vector>

using namespace std;



int main(){
    int res[56]={0};
    string ch;
    cin>>ch;
    for(int i=0;i<ch.length();i++){
        
        if(isalpha(ch[i])){
            if(isupper(ch[i]))
            res[ch[i]-'A']++;
            else res[ch[i]-'a'+26]++;
        }
        
    }
    //next_permutation(ch.begin(),ch.end());
    ch = "";
    for(int i= 0;i<26;i++){
        if(res[i])while(res[i]--)ch+='A'+i;
        if(res[i+26])while(res[i+26]--)ch+='a'+i;
       
    }
    cout<<ch<<endl;

    return 0;
}