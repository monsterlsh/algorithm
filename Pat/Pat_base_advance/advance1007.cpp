#include <iostream>
#include<vector>
using namespace std;
struct stu{
    string id;
    string in;
    string out;
};
int main(){
    vector<stu>res;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++;){
        string id ,in,out;
        cin>>id>>in>>out;
        stu s = {id,in,out};
        vector.push_back(s);
    }
}