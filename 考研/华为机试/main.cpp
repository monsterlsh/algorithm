#include<iostream>
using namespace std;

typedef struct List{
    int addr;
    int data;
    List * next;
    List(int x,int y):addr(x),data(y),next(NULL){}
	
    
} *head;
void read();
int main(){
    List node(1,2);
    cout<<node.addr<<endl;
}
void read(){
    int  addr,data;
    cin>>addr>>data;
    List node(addr,data);
    cout<<node.addr<<endl;
}
