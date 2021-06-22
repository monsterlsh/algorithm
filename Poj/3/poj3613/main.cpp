#include<cstring>
#include<cstdio>

#define min(x,y) (x<y?x:y)

const int inf = 0x3f3f3f3f;

class MatrixFloyd{
public:

    int n,m,s,t,k;
    int ans[205][205],tmp[205][205],mp[205][205],dis[205][205],v[1005];

    void init(){
        n=0;
        memset(v,-1,sizeof(v));
        for(int i=0;i<200;i++){
            for(int j=0;j<200;j++)
                ans[i][j]=tmp[i][j]=mp[i][j]=dis[i][j]=inf;
            ans[i][i]=0;
        }
    }

    void in(){
        init();
        scanf("%d%d%d%d",&k,&m,&s,&t);
        while(m--){
            int w,x,y;scanf("%d%d%d",&w,&x,&y);
            if(v[x]==-1)v[x]=n++;                //������ɢ��
            if(v[y]==-1)v[y]=n++;
            mp[v[x]][v[y]]=mp[v[y]][v[x]]=min(mp[v[x]][v[y]],w);
        }
        sove();
        printf("%d\n",ans[v[s]][v[t]]);
    }

    void floyd(int c[][205],int a[][205],int b[][205]){
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    c[i][j]=min(c[i][j],a[i][k]+b[k][j]);
    }

    void sove(){
        while(k){
            if(k&1){               //������λΪ1
                floyd(dis,ans,mp);              //��dis����ans��mp��˵ľ��󣬼�c=a+b
                memcpy(ans,dis,sizeof(ans));    //��ֵ��ans
                memset(dis,0x3f,sizeof(dis));   //�ڳ�ʼ��dis
            }
            floyd(tmp,mp,mp);
            memcpy(mp,tmp,sizeof(mp));            //mp��ʾ����mp^2^n  nΪ�����Ƴ���
            memset(tmp,0x3f,sizeof(tmp));
            k>>=1;
        }
    }


}mf;

int main()
{
    mf.in();
    return 0;
}
