#include <iostream>
#include<vector>
#include <cstring>
#include<algorithm>
#include<map>
using namespace std;
#define RE
enum direction {NO,LEFT,UP,RIGTH,DOWN};
struct node{
    
    direction l,u,r,d;
    node(direction x,direction y,direction z,direction m):l(x),u(y),r(z),d(m){}
};
size_t n,k;
map<size_t,size_t>sizes;
bool g[82][82];
vector<vector<node>> graph(11,vector<node>(11,node(NO,NO,NO,NO)));
void printGraph(){
    for(size_t i=1;i<=n;i++){
        for(size_t j=1;j<=n;j++){
            if(graph[i][j].u==UP)
            cout<<g[i][j]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    
}
void buildGraaph(){
    char dir;
    size_t x,y;
    fill(g[0],g[0]+121,0);
    fill(graph.begin(),graph.begin()+11,vector<node>(11,node(NO,NO,NO,NO)));
    for(size_t i=0;i<k;i++){
        cin>>dir>>x>>y;
        
        if(dir=='H'){
            g[x][y]=1;
            g[x][y+1]=1;
            graph[x][y].r=RIGTH;
            graph[x][y+1].l=LEFT;
        }
        else if(dir=='V'){
            g[y][x]=1;
            g[y][x+1]=1;
            graph[y][x].d=DOWN;
            graph[y+1][x].u=UP;
        }
        
    }
   
}
//t1 t2
//t3 t4
//node & t2,node & t3,node & t4
bool judgleSingle(node & t1){
    return t1.r==RIGTH && t1.d==DOWN;
}
bool judgleSecond(node & t1){
    return t1.u==UP && t1.l==LEFT;
}
bool judglethrid(node & t1){
    return t1.u==UP && t1.r==RIGTH;
}
bool judgeright(node & t1){
    return t1.r==RIGTH;
}
bool judgedown(node & t1){
    return t1.d==DOWN;
}
bool judgeup(node & t1){
    return t1.u==UP;
}
bool judgeleft(node & t1){
    return t1.l==LEFT;
}
size_t dfs(size_t i, size_t j){
    
    if(i<n && i>=1 && j<n&& j>=1){
       
        size_t sum = 0,stp=1;
        size_t yy=j+1,xx=i+1;
        bool first = true;
        if(judgleSingle(graph[i][j]))
        while( stp>=1){
            if(first){
                for(;yy<=n &&judgeleft(graph[i][yy]) ;yy++,stp++);
                yy--;stp--;
                if(stp==0)break;
            }else {yy = j+stp;}
            
            first = false;
            //bug
            xx=i+1;
            for(;xx<=(i+stp) && judgeup(graph[xx][yy]);xx++);
            xx--;
            if(xx==(i+stp) && yy==(j+stp)&&judgleSecond(graph[xx][yy])){
                if(stp==1){sum++;sizes[stp]++; break;}
                for(--yy;yy>j && judgeleft(graph[xx][yy]);yy--);
                if(yy!=j || (j==yy&&!judglethrid(graph[xx][yy])))stp--;
                else{
                    for(--xx;xx>i && judgeup(graph[xx][yy]);xx--);
                    if(xx!=i)stp--;
                    else{   
                    sum++;
                    sizes[stp]++;
                    stp--;
                    }
                }
            }else{
                stp--;
            } 
        }
        return sum;
    }//if i j
    return 0;
}
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    /*buildGraaph();
    printGraph();*/
    
    size_t kase=0;
    while(scanf("%zd %zd",&n,&k)!=EOF){
        if(kase) printf("\n**********************************\n\n");
        sizes.clear();
        buildGraaph();
        printf("Problem #%zd\n\n",++kase);
        //printGraph();
        size_t num =0;
        for(size_t i=1;i<n;i++){
            for(size_t j=1;j<n;j++)
            num += dfs(i,j);
        } 
        //printf("ans : %zd\n",num);
        map<size_t,size_t>::iterator it = sizes.begin();
        while(it!=sizes.end()){
            printf("%zd square (s) of size %zd\n",it->second,it->first);
            it++;
        }
        if(sizes.empty()){
            printf("No completed squares can be found.\n");
        }
        //printGraph();
       
    }
}
