#include <iostream>
using namespace std;
int sum(double arr[], int x);

int main()
{
    double arr[100];
    sum(arr, 2);
    int x = 2;
    for (int i = 0; i < 2; i++)
    {
        //if(i==x)cout<<"why don't stop??? ";
        cout << "value : " << i << endl;
    }
}
int sum(double arr[], int x)
{
    double tmp;

    cout << "x = " << x << endl;
}