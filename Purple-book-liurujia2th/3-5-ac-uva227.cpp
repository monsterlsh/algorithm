#include <iostream>
#include <algorithm>
#include <string>

using namespace std ;


int main()
{
	char c ;
	int num = 0 ;									//计数器 
	int num1, num2 ;								//二维数组空格的横、纵坐标 
	while((c=getchar() )&& c != 'Z') {		 
		char a[5][5] ;
		a[0][0] = c ;	
		if(c==' ') {
			num1 = 0 ; num2 = 0 ;
		} 
		//二维数组赋值			
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				if(i != 0 || j != 0) {
					a[i][j] = c = getchar() ;
					(c == ' ' ) ? (num1=i,num2=j) : (i = i) ;   	//冒号后面凑字数 
				}
			} 
			getchar() ;									//吸收回车 
		} 
		//输入修改序列
		bool flag = false ; 
		string s ;												//用string比较方便 
		while(char r = getchar()) {								
			if(r=='0') break ;
			else if(r==' ') continue ;
			else s+=r; 
		}
		getchar() ; 
		//修改序列后有一个回车，会被第一个c字符的getchar接受到 
		

		int len = s.length() ;
		//ABLR分别对应不同操作。
		for(int i = 0; i < len; i++) {		//可以换成auto 
//		cout << num1 <<' '<< num2 << endl ;
			if(s[i] == 'A') {
				int n1 = num1 , n2 = num2 ;						//空格所在行列和待交换字符所在行列 
				num1-- ;
				if((num1>=0)&&(num1<5)&&(num2>=0)&&(num2<5)) 
					swap(a[n1][n2],a[num1][num2]) ;
				else {
					flag=true ;break; 
				}
			}
			else if(s[i] == 'B') {
				int n1 = num1 , n2 = num2 ;						//空格所在行列和待交换字符所在行列 
				num1++ ;
				if((num1>=0)&&(num1<5)&&(num2>=0)&&(num2<5)) 
					swap(a[n1][n2],a[num1][num2]) ;
				else {
					flag=true ;break; 
				}
			}
			else if(s[i] == 'L') {
				int n1 = num1 , n2 = num2 ;						//空格所在行列和待交换字符所在行列 
				num2-- ;
				if((num1>=0)&&(num1<5)&&(num2>=0)&&(num2<5)) 
					swap(a[n1][n2],a[num1][num2]) ;
				else {
					flag=true ;break; 
				}
			}
			else if(s[i] == 'R') {
				int n1 = num1 , n2 = num2 ;						//空格所在行列和待交换字符所在行列 
				num2++ ;
				if((num1>=0)&&(num1<5)&&(num2>=0)&&(num2<5)) 
					swap(a[n1][n2],a[num1][num2]) ;
				else {
					flag=true ;break; 
				}
			}
		} 
		//输出： 
		num++ ; 
		if(num != 1) 
			cout << endl ; 
		cout << "Puzzle #" << num <<":" << endl ; 
		if(flag==false) 
			for(int i = 0; i < 5; i++) {
				for(int j = 0; j < 5; j++) { 
					if(j != 0) cout << ' ' ;
					cout << a[i][j] ;
				} 
				cout << endl ;
			}
		else 
			cout << "This puzzle has no final configuration." << endl ;
	}
	return 0 ;
}
