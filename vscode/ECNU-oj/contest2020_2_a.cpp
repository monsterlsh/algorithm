#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
 double ans,tmpans; string str ="",s2="";int jiema=0;
string tojiema(int jiema){
    string ss(12,'0');
    if(tmpans<0) ss[0]=1;
    int i=11;
    while(jiema){
        int mod = jiema%2;
        if(mod)ss[i]='1';
        jiema /=2;
        i--;
    }
    return ss;
}
void toff(){
     
    string ss = str+s2,fin="";
    int i=0,n=0,idx=0;
     int sum=0;
    while(n<ss.length()){
       sum=0;
        for(;i<4;i++){
            if(ss[n]=='1')sum += pow(2,3-i);
            n++;
        }
        if(sum<10)fin+=sum+'0';
        else fin+=sum-10+'A';
        i=0;
        idx++;
        if(idx==2){cout<<fin<<(n!=ss.length()?"-":"\n");idx=0;fin="";}
    }
    
}
int main(){
   
    
     freopen("input.in","r",stdin);
     freopen("output.out","w",stdout);
    scanf("%lfd",&tmpans);
    ans = abs(tmpans);
    int z = int(ans);
    double xiaoshu = ans-z;
    
    while(z){
        int mod = z%2;
        z =z/2;
        str += mod+'0';
    }
    
    reverse(str.begin(),str.end());
   
    int i=1;
    while(i<str.length()){
        s2 +=str[i++];
    }
    if(s2.length()!=0){
      
        jiema = s2.length();
    }
    jiema += 1023;
    str = tojiema(jiema);
    while(xiaoshu!=0){
        double tmp = xiaoshu*2;
        int s = int(tmp);
        s2+=s+'0';
        xiaoshu = tmp-abs(s);
        if(s2.length()>=52)break;
    }
    if(s2.length()<52) {
        string tmp(52-s2.length(),'0');
        s2.append(tmp);
        }
   
    toff();
}
