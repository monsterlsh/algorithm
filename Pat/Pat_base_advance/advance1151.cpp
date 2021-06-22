#include<iostream>
using namespace std;
int inorder[1000];
int preorder[1000];
int m,n;
struct Treenode{
    int num;
    Treenode * left;
    Treenode * right;
    Treenode(int x) : num(x), left(NULL), right(NULL) {}
};
int main(){
    scanf("%d %d",&m,&n);
    for(int i =0;i<n;i++) scanf("%d",&inorder[i]);
    for(int i =0;i<n;i++) scanf("%d",&preorder[i]);
    Treenode node(inorder[0]);
    
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
    }

}
Treenode * Build(Treenode * node,int l,int r){
        int mid = l;
        for(;mid<=r;mid++){
            if(inorder[mid]==preorder[l])break;
        }
      
}
int find(int u,int v){

}