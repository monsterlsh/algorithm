#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include <utility>
using namespace std;
bool judge(int n);
//1008
void reverseArray(vector<int> &arr, unsigned pos, unsigned end);
void swap(int &a, int &b);
void printArray(const vector<int> &arr);
void reverseKbits(vector<int> &arr, int k);
void testpat1008_noReverse();

//1009
void printArray(const vector<string> &arr);
string reverseSentence();
void split(const std::string& str, 
           std::vector<std::string>& tokens, 
           const std::string delim);

void pat1007();
void pat1008();
void pat1009();


bool judge(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void pat1007()
{
    int n;
    scanf("%d", &n);
    int pre = 3, end = pre + 2, res = 0;
    //bool odd = true;
    while (end <= n)
    {
        if (judge(end))
        {
            if (end == pre + 2)
                res++;
            pre = end;
        }
        end += 2;
    }
    cout << res << endl;
}
/*
****************************1008 数组元素循环右移问题*******************************************
*/
void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
void reverseArray(vector<int> &arr, unsigned pos, unsigned end)
{
    if (pos > arr.size() || end > arr.size() || end < pos)
    {
        cout << "WARNING: Wrong paramter input of pos and end!" << endl;
        return;
    }
    for (unsigned i = pos; i <= (pos + end) >> 1; i++)
    {
        swap(arr[i], arr[end + pos - i]);
    }
}
void printArray(const vector<int> &arr)
{
    int i = 0;
    for (; i < arr.size() - 1; i++)
        cout << arr[i] << " ";
    if (i < arr.size())
        cout << arr[i] << endl;
}
void reverseKbits(vector<int> &arr, int k)
{
    int len = arr.size(),next,pre=0,povit;
    k %= len;
    vector<bool>flags(len,false);
    for (int i = 0; i < k; i++)
    {
        next = i;
        povit = arr[i];
        
        while (!flags[next])
        {
            
           swap(povit,arr[next]);
           flags[next]=true;
           next = (next+k)%len;
            
        }
        swap(povit,arr[next]);
         /*cout<<"the "<<pre++<<" th: ";
        printArray(arr);*/
    }
}
void testpat1008_noReverse(){
    vector<int>arr{1,2};
    reverseKbits(arr,3);
    printArray(arr);
}
void pat1008()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    k %= n;
    reverseArray(arr, 0, n - 1);
    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);
    /*reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());*/
    //reverseKbits(arr,k);
    printArray(arr);
}
/************************1009*********************************/
string reverseSentence(){
    /*string str;
    getline(cin,str);*/
    string str = "Hello World Here I Come";
    vector<string>res;
    split(str,res," ");
    printArray(res);
    return str;
}
void printArray(const vector<string> &arr)
{
    int i = arr.size()-1;
    for (; i >0; i--)
        cout << arr[i] << " ";
    if (i >= 0)
        cout << arr[i] << endl;
}
void split(const std::string& str, 
           std::vector<std::string>& tokens, 
           const std::string delim) {
    tokens.clear();
    auto start = str.find_first_not_of(delim, 0);       // 分割到的字符串的第一个字符
    auto position = str.find_first_of(delim, start);    // 分隔符的位置
    while (position != std::string::npos || start != std::string::npos) {
        // [start, position) 为分割下来的字符串
        //cout<<" start: "<<start<<" position: "<<position<<endl;
        if(position != std::string::npos)
        tokens.emplace_back(std::move(str.substr(start, position - start)));
        else 
        tokens.emplace_back(std::move(str.substr(start)));
        start = str.find_first_not_of(delim, position);
        position = str.find_first_of(delim, start);
    }
}