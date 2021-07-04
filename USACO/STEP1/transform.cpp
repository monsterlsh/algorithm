#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;
#define RE
    #ifdef AN
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    #endif
    
    #ifdef RE
    ofstream fout("output.out");
    ifstream fin("input.in");
    #endif
int n;
vector<char>image[10],trans[10];
void read(){
    fin>>n;
    for(int i=0;i<n;i++)
    fill(image[i].begin(),image[i].end(),0);
    char c;
    for(int i=0,j=0;i<n;i++)
        while(fin>>c && (c=='@'||c=='-'))image[i][j++]=c;
    for(int i=0,j=0;i<n;i++)
        while(fin>>c && (c=='@'||c=='-'))trans[i][j++]=c;
}
void transform_1(){

}
int main(){

}