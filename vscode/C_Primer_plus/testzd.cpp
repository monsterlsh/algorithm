#include<iostream>
using namespace std;
int main(){
size_t x = 50;
printf("Type int has a size of %zd bytes.\n", x);
printf("Type int has a size of %zd bytes.\n", sizeof(int));
printf("Type char has a size of %zd bytes.\n", sizeof(char));
printf("Type long has a size of %zd bytes linhaohao.\n", sizeof(long));
printf("Type long long has a size of %zd bytes.\n",
sizeof(long long));
printf("Type double has a size of %zd bytes.\n",
sizeof(double));
printf("my Type small long double has a size of %zd bytes.pig %d %d \n",
sizeof(long double));
float salary;
printf("\aEnter your desired monthly salary:");/* 1 */
printf(" $_______\b\b\b\b\b\b\b"); /* 2 */
scanf("%f", &salary);
printf("\n\t$%.2f a month is $%.2f a year.", salary,
salary * 12.0); /* 3 */
printf("\rGee!\n");
}