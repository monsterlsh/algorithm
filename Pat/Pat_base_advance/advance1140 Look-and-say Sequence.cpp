#include<iostream>
using namespace std;
int main(){
    string d;
    int n;
    cin>>d>>n;
   // cout<<d<<"  "<<n<<endl;
    string s = "";
    for(int i=2;i<n;i++){
        char pre = d[0];
        for(int j=0;j<d.size();j++){
            pre = d[j];
            s+=d[j];
            int sum = 0;
            while(j<d.size()&&pre == d[j]){sum++;j++;}
            s+=sum+'0';
            if(j==d.size())break;
            j--;
            
        }
        d =s;
        s="";
    }
    cout<<d<<endl;

}