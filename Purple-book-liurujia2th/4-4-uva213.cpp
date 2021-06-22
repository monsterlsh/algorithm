/**
 * Message Decoding UVA - 213 
 * 
 * ShuoHao Lin
 */
#include <iostream>
#include <cstring>
#include<cctype>
using namespace std;
#define RE
// 0-1 00 01 10-3 000 001 010 011 100 101 110  7
char text[8][1<<8];
size_t len[8];
char c;
char ch[8];
size_t dex,kase=0;
string str="";
void read(){
    
    str="";
    kase++;
    dex=0;
    memset(len,0,sizeof(len));
    while((c = getchar()) == '\n');
    size_t i=0;
    while(c!='\n' && c!=EOF){
        if(i<(size_t)(1<<(dex+1))-1){
            text[dex][i]=c;
            i++;
            c = getchar();
        }
        if(i>=(size_t)(1<<(dex+1))-1 || c=='\n') {
            len[dex]=i;
            i=0;
            dex++;
        }
        
    }
}
size_t getnums(size_t n){
    size_t sum=0;
    for(size_t i=0,j=n-1;i<n;i++,j--){
        if(ch[i]=='1')sum += (1<<(j));
    }
    return sum;
}
 
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
   
    while (true)
    {
        read();
        if(c==EOF)break;
        bool flag = true;
        size_t nums = 0;
        while ( true)
        {   
            size_t i = 0,nextlen=!flag?nums:3;
            //ch[0]=ch[0]=='\n'?getchar():ch[i];
            for(; i<nextlen ;i++){
                ch[i]=getchar();
                ch[i]=ch[i]=='\n'?getchar():ch[i];
            }
            if(flag && ch[0]=='0'&&ch[1]=='0'&&ch[2]=='0')break;
            if(flag) {nums = getnums(3);flag=false;continue;}
            else{
                i = getnums(nextlen);
                if(i==(size_t)(1<<nextlen)-1){
                    flag = true;
                    continue;
                }
                if(i<len[nums-1])
                    str+=text[nums-1][i];
            }
        }
        cout<<str<<endl;
    }
}
