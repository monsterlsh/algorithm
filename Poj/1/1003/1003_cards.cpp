#include<iostream>
using namespace std;

int main(){
    double sum;
    while(cin>>sum && sum!=0.0){
        double i = 1.0,allsum = 0.0;
        while(++i){
            allsum += 1/i;
            if(allsum >=sum) {
                    i--;
                    cout<<i<<" card(s)"<<endl;
                    break;
        }
    }

}
return 0;
}
