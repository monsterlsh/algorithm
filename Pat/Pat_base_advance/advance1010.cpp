#include<iostream>
#include<algorithm>
#include<cctype>
#include<cmath>
using namespace std;
int change(string str,int radix);
bool judge(char c,int radix);
int findRadix(string s,int res);
int pow2(int radix);
int main(){
    string str1,str2;
    int tag,radix;
    cin>>str1>>str2>>tag>>radix;
    if(tag==2){
        string tmp = str1;
        str1 = str2;
        str2 = tmp;
    }
    int res = change(str1,radix);
    //if(res == -1)cout<<"str1 no "<<endl;
    int radix2 = findRadix(str2,res);
    if(res!=-1&&radix2!=-1)cout<<radix2<<endl;
    else cout<<"impossible"<<endl;
}
int findRadix(string s,int res){
    char it = *max_element(s.begin(),s.end());
    int low = (isdigit(it)?it-'0':it-'a'+10)+1;
    int high= max(low,res);
    while(low<=high){
        int mid = (low + high)/2;
        int t = change(s,mid);
        //t<0????
        if(t<0 || t>res)high = mid - 1;
        else if(t==res)return mid;
        else low = mid + 1;
    }
    return -1;
}
int pow2(int radix){
    if(radix<=2) return 2;
    if(radix<=8)return 8;
    if(radix<=10)return 10;
    if(radix<=16)return 16;
    return -1;
}
int change(string s,int radix){
    int i = s.length()-1,j=0;
    int sum = 0;
    while(i>=0){
        if(!judge(s[i],radix))return -1;
        int ch = s[i]>='0'&&s[i]<='9'?s[i]-'0':s[i]-'a'+10;
        ch = pow(radix,j)*ch;
        sum += ch;
        i--;
        j++;
    }
    return sum;
}
bool judge(char c,int radix){
    if(c>='0'&&c<='9'){
        if(c-'0'>=radix)return false;
        else return true;
    }else if(c>='a'&&c<='z'){
        if(c-'a'+10 >=radix)return false;
        else return true;
    }
    return false;
}