#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 #define RE
#define maxn 10
#define rbe res.begin(),res.end() 
typedef struct arc{
    size_t w,h;
    bool v = 0;
    size_t wv=0,hv=0;
};

bool bmp(const arc & a,const arc&b){
    if(a.w==b.w)return a.h<b.h;
    return a.w<b.w;
}

int main()
{
#ifdef RE
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
#endif
bool flag = true;
while(flag){
    size_t a,b;
    vector<arc>res(6);
    bool result = true;
    for(int i=0;i<6;i++){
        if(scanf("%zd %zd",&a,&b)==EOF){
            flag = false;
            break;
        }
        res[i].w=min(a,b);
        res[i].h=max(a,b);
        res[i].v=0;
        res[i].wv=0;
         res[i].hv=0;
    }
    if(!flag)break;
    sort(rbe,bmp);
    size_t same = 0;
    for(size_t i=1;i<6;i+=2){
        if(res[i].w!=res[i-1].w && res[i].h!=res[i-1].h ){
            result = false;
            break;
        }
    }
    for(size_t i=0;i<6 && result;i++){
        if(res[i].wv==2&&res[i].hv==2)res[i].v=1;
        for(size_t j=i%2==0?i+2:i+1;j<6;j++){
            if(!res[i].v&&!res[j].v && res[i].w==res[j].w ){
                res[i].wv++;
                res[j].wv++;
                if(res[i].wv==2&&res[i].hv==2)res[i].v=1;
                if(res[j].wv==2&&res[j].hv==2)res[j].v=1;
            }
             if(!res[i].v&&!res[j].v && res[i].w==res[j].h ){
                  res[i].wv++;
                res[j].hv++;
                if(res[i].wv==2&&res[i].hv==2)res[i].v=1;
                if(res[j].wv==2&&res[j].hv==2)res[j].v=1;
             }
              if(!res[i].v&&!res[j].v && res[i].h==res[j].w ){
                  res[i].hv++;
                res[j].wv++;
                if(res[i].wv==2&&res[i].hv==2)res[i].v=1;
                if(res[j].wv==2&&res[j].hv==2)res[j].v=1;
             }
              if(!res[i].v&&!res[j].v && res[i].h==res[j].h ){
                  res[i].hv++;
                res[j].wv++;
                if(res[i].wv==2&&res[i].hv==2)res[i].v=1;
                if(res[j].wv==2&&res[j].hv==2)res[j].v=1;
             }
        }
        
    }
    for(size_t i=0;i<6;i++) {
        if(res[i].v==1)same++;
    }
    if(same!=6)result = 0;
    if(!result){ printf("IMPOSSIBLE\n");continue;}
    else printf("POSSIBLE\n");
}
    
}
