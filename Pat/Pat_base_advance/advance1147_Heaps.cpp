#include<iostream>
#include<vector>
using namespace std;
void order(vector<int>&postorder,vector<vector<int>>&res,int root,int i);
int main(){
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    int m,n;
    scanf("%d %d",&m,&n);
    vector<vector<int>>res(m+1,vector<int>(n+1));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&res[i][j]);
        }
    }
    
    for(int i=1;i<=m;i++){
        int maxheaps = -1;
        int root = 1,len =res[i].size() ;
       
        while(root<len){
            int left = root*2,right=(root)*2+1;
            //if()
            if(
                (left<len && res[i][root]<res[i][left] &&  maxheaps!=0)
                ||  (right<len && res[i][root]<res[i][right] &&  maxheaps!=0)
                ){
                if(maxheaps!=-1){
                    maxheaps = -1;
                    break;
                }else maxheaps=0;
            }
            if(
                (left<len && res[i][root]>res[i][left] &&  maxheaps!=1)
               || (right<len && res[i][root]>res[i][right] &&  maxheaps!=1)
               ) {
                if(maxheaps!=-1){
                    maxheaps = -1;
                    break;
                }else maxheaps=1;
            }
            root++;
        }
        vector<int>postorder;
        order(postorder,res,1,i);
        if(len==2)maxheaps=1;
        if(maxheaps==-1)cout<<"Not Heap\n";
        else if(maxheaps==0)cout<<"Min Heap\n";
        else if(maxheaps==1)cout<<"Max Heap\n";
        for (size_t j = 0; j <postorder.size(); j++)
        {

            cout<<postorder[j]<<(j!=postorder.size()-1?" ":"\n");
        }
        
    }

}
void order(vector<int>&postorder,vector<vector<int>>&res,int root,int i){
     if(root<res[i].size()){
         order(postorder,res,2*root,i);
         order(postorder,res,2*root+1,i);
        postorder.emplace_back(res[i][root]);
     }
}