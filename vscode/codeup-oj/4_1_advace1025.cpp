#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct STU{
    char id[15];
    int scores;
    int location_num;
    int location_rank;
}stu[301];
int n,k;
bool cmp(const STU & a,const STU & b){
    return a.scores==b.scores?strcmp(a.id,b.id)<0:a.scores>b.scores;
}
int main(){
    int num=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%s %d",stu[num].id,&stu[num].scores);
            stu[num].location_num=i;
            num++;
        }
        sort(stu+num-k,stu+num,cmp);
        stu[num-k].location_rank=1;
        for(int j=num-k;j<num-1;j++){
            if(stu[j].scores==stu[j+1].scores) stu[j+1].location_rank=stu[j].location_rank;
            else stu[j+1].location_rank=j+2-(num-k);
        }
    }
    printf("%d\n",num);
    sort(stu,stu+num,cmp);
    int r=1;
    for(int i=0;i<num;i++){
        if(i>0 && stu[i].scores!=stu[i-1].scores)r=i+1;
        printf("%s ",stu[i].id);
        printf("%d %d %d\n",r,stu[i].location_num,stu[i].location_rank);
    }
}