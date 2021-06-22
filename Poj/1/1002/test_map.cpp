#include<iostream>
#include<map>
#include<string>
using namespace std;
typedef struct tagStudentinfo{
    int n;
    string str;
}Studentinfo, *PStudentinfo; //学生信息
class Sort{
public:
    bool operator () (tagStudentinfo const & _A,tagStudentinfo const & _B) const
    {
        if(_A.n<_B.n) return true;
        else if(_A.n == _B.n) return _A.str.compare(_B.str)<0;
        return false;
    }
};
int main(){
    map<int,string> maps;
    maps.insert(map<int,string>::value_type(1,"one"));//map<int,string>::value_type(1,"one")
    maps.insert(pair<int,string>(1,"another_one"));
    maps.insert(pair<int,string>(2,"two"));//pair<int,string>(2,"two")
    maps.insert(pair<int,string>(3,"three"));
    map<int,string>::iterator it;
    for(it = maps.begin();it!=maps.end();it++){
        cout <<it->first<<"  "<<it->second<<endl;
    }
    //pair检测是否插入正确
    pair<map<int,string>::iterator,bool> Insert_pair;
    Insert_pair = maps.insert(pair<int,string>(4,"four"));
    if(Insert_pair.second == true)
        cout<<"Insert successfully"<<endl;
    else
        cout<<"Insert Failure"<<endl;
    Insert_pair = maps.insert(pair<int,string>(4,"another-four"));
    if(Insert_pair.second == true)
        cout<<"Insert successfully"<<endl;
    else
        cout<<"Insert Failure"<<endl;

        //数组
        maps[5]="five";
        maps[5]="another-five";
         maps.insert(map<int,string>::value_type(1,"other-one"));
        for(it = maps.begin();it!=maps.end();it++){
        cout <<it->first<<"  "<<it->second<<endl;
    }

    //maps 的大小
    cout << "maps capacity: " << maps.size()<<endl;
    //反向迭代器:
    it = maps.find(7);
    if(it != maps.end())
        cout << it->second<<endl;
        else if(it == maps.end())
            cout<<"not found"<<endl;
    /************************************/
    cout<<"*******************************\n";
    it = maps.lower_bound(4);
    cout<<"it`s : " << it->first << " " << it->second<<endl;
    it = maps.upper_bound(4);
    cout<<"it`s : " << it->first << " " << it->second<<endl;

    pair<map<int ,string>::iterator,map<int ,string>::iterator> mappair;
    mappair = maps.equal_range(4);
    if(mappair.first == mappair.second) cout<<"No Find\n";
    else cout << mappair.first->first<<endl;
    cout<<"*****删除***********"<<endl;
    int n = maps.erase(1);
    cout << n << endl;
    for(it = maps.begin();it!=maps.end();it++){
        cout << it->first<<"  "<<it->second<<endl;
    }
    cout<<"*******学生信息****************"<<endl;
    map<Studentinfo,int,Sort> mapStudent;
    map<Studentinfo,int>::iterator itStu;
    Studentinfo stu;
    stu.n = 1;
    stu.str="Bob";
    mapStudent.insert(map<Studentinfo,int>::value_type(stu,90));
    stu.n = 2;
    stu.str="lsh";
    mapStudent.insert(map<Studentinfo,int>::value_type(stu,100));
    stu.n = 3;
    stu.str="z";
    mapStudent.insert(map<Studentinfo,int>::value_type(stu,70));
    stu.n = 4;
    stu.str="lss";
    mapStudent.insert(map<Studentinfo,int>::value_type(stu,80));
    stu.n = 3;
    stu.str="zjhpp";
    mapStudent.insert(map<Studentinfo,int>::value_type(stu,65));
    for(itStu=mapStudent.begin();itStu!=mapStudent.end();itStu++){
        cout<< "name :"<<itStu->first.str<<"`s score is"<<itStu->second<<endl;
        //cout<<itStu->first.str<<"`s score is"<<itStu.second<<endl;
    }
    /******************/
    cout << "******Test STRING ******\n";
    string str= "12356";
    str.insert(3,"-");
    cout<<str<<endl;
}
