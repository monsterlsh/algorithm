#include <iostream>
#include <cstring>
using namespace std;
#define RE
size_t sames[][6] = {{0, 1, 2, 3, 4, 5},  //135246  142536  154326
                     {4, 0, 2, 3, 5, 1},  //513462 541632 564312 
                     {3, 1, 0, 5, 4, 2},  //421653
                     {5, 1, 3, 2, 4, 0},  //624351
                     {2, 1, 5, 0, 4, 3},  //326154
                     {1, 5, 2, 3, 0, 4}}; //263415
int main()
{
#ifdef RE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    string str1, str2;
    while (cin>>str1)
    {
        str2 = str1.substr(6,6);
        str1 = str1.substr(0,6);
        bool flag = false;
        for(size_t i=0;i<6 && !flag;i++){
            size_t j=0;
            for(;j<6 && str2[sames[i][j]]==str1[j];j++);
            if(j==6){flag=true;break;}
            int k=3;
            /*while(k--){
                swap(sames[i][1],sames[i][2]);
                swap(sames[i][3],sames[i][4]);
                swap(sames[i][4],sames[i][1]);
                for(;j<6 && str2[sames[i][j]]==str1[j];j++);
                if(j==6){flag=true;break;}
            }*/
        }
        if(flag) printf("TRUE\n");
        else printf("FALSE\n");
    }
}
