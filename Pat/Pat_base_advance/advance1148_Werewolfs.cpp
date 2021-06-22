#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> pp;
vector<int>players;
int n,first,second,sum;
bool find_pp_firstisTrue(int first,int second);
int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    cin>>n;
    players.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>players[i];
        //if(players[i]<0)sum++;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(find_pp_firstisTrue(i,j) ||find_pp_firstisTrue(j,i) ){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    cout<<"No Solution";
}
bool find_pp_firstisTrue(int first,int second){
    //bool firstistrue = true;
    //if(first == 1 && second==3) ;
    bool fs = (players[second]>0 && players[second]==first ) || (players[second]<0 && 0-players[second]!=first);

    if(!(
        (players[first]<0 && (0-players[first]==second ) && fs  )  || 
        (players[first]>0 && (players[first]!=second ) && fs) 
      
       )){
          return false;
    }
   bool flag = false;
          for(int i=1;i<=n;i++){
              if(i==first || i==second) continue;
              //say false
              if( (players[i]>0 && (players[i]==first || players[i]==second)   ) || 
                (players[i]<0 && (0-players[i]!=first && players[i]!=second) ) 
                   ){
                    for(int j=1;j<=n;j++){
                        
                        if(j==first || j==second || j==i) continue;
                        //say true
                        if( (players[j]>0 && (players[j]!=first && players[j]!=second)   ) || 
                            (players[j]<0 && (0-players[j]==first || players[j]==second) ) 
                            ){
                                
                                flag = true;
                            }
                            else {flag = false;break;}
                    }   
              }
              if(flag)return flag;    
          }
          return false;
}
