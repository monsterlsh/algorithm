#include<iostream>

#define len 10005

using namespace std;

void print(int a[],int end,int start){
    for(int i=start;i<=end;i++)cout<<a[i];
    cout<<endl;
}
void bigDividend(string & a,string & b){
    int dividend[len]={0},divisor[len]={0},sum[len]={0},
    i=0,j=0,start=0,end=b.size()-1,bsize=b.size(),
    ch =0;
    char quo='0';
    string quotients,remainder;
    for(;i<a.size();i++)  dividend[i] = a[i]-'0';
    for(i=0;i<b.size();i++)  divisor[i] = b[i]-'0';
    while(end<a.size()){
        //检查够不够减
        i = start;j=0;
       
        if(dividend[i]<divisor[j] && end-start+1==bsize){
                quotients.push_back(quo);end++;quo='0';
        }
        //if 9999666  /  9999555 or  99955/99966
        else if( dividend[i]==divisor[j] && end-start+1==bsize){
            if(quo=='0'){
                while(dividend[i]==divisor[j] && j<bsize){
                    i++;j++;
                }
                //999/999
               /* if(j==bsize){
                    quotients.push_back('1');quo='0';
                    start=end+1;
                }*/
                 if(j<bsize && dividend[i]<divisor[j]){
                    quotients.push_back(quo);quo='0';end++;
                }
            }else if(quo!='0'){
                while(dividend[i]==divisor[j] && j<bsize){
                    i++;j++;
                }
               /*if(j==bsize){
                    quotients.push_back(quo+1);quo='0';
                    end++;
                    start=end;
                }*/
                if(j<bsize && dividend[i]<divisor[j]){
                    quotients.push_back(quo);quo='0';
                    //start++;
                    end++;
                   /* if(end-start+1<bsize){
                        end++;
                        if(end>=a.size())break;
                    }*/
                }
            }
        }
       // else{
           if(end>=a.size())break;
             cout<<" before ";print(dividend,end,start);
            for(j=bsize-1,i=end;j>=0;i--,j--){
                dividend[i]-=ch;
                ch=dividend[i]<divisor[j]?1:0;
                dividend[i] -= divisor[j];
                if(dividend[i]<0)dividend[i]+=10;
            }
            if(ch)dividend[i]--;
            ch = 0;
            quo++;
            cout<<" after ";
            print(dividend,end,start);
            cout<<" quo : "<<quo<<endl;
            /****/
            if(dividend[start]==0 && end-start+1>bsize && dividend[end]!=0 ) { start++; }
            if(dividend[start]==0 && dividend[end]==0)
            {
                quotients.push_back(quo);quo='0';
                int tmp = end+1;
                i=0;j=end+bsize;
                while(end<j){
                    end++;
                    if(end>=a.size())break;
                    if(i>=1)quotients.push_back('0');
                    i++;
                }
                start = tmp;
                /*while(dividend[start]==0){
                    start++;
                    if(end-start+1<bsize){
                        end++;
                        if(end>=a.size())break;
                        //?????
                        if(end-start+1<bsize-1)
                        quotients.push_back('0');
                    }
                }*/
            }
            else 
            while(dividend[start]==0){
                start++;
                if(end-start+1<bsize){
                    end++;
                    if(end>=a.size())break;
                    quotients.push_back('0');
                }
            }
            
        //}
    }
    
    while(!quotients.empty()&& quotients[0]=='0')quotients=quotients.substr(1);
    cout<<quotients<<" ";
    i=start;
    while(i<a.size() && dividend[i]==0)i++;
    for(;i<a.size();i++)cout<<dividend[i];
    cout<<endl;
}

int main(){
    freopen("input.in","r",stdin);  
    freopen("output.out","w",stdout);
    string a,b;
    while(cin>>a>>b){
        bigDividend(a,b);
    }
    
    //cout<<" right :"<<1122999911/9812<<" "<<1122999911%9812<<endl;
}