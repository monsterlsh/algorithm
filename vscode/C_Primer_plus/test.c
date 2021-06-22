#include<stdio.h>
#include<limits.h>
#include<inttypes.h>
int main(){
   /* int x= -100;
    printf("%d %o %x\n",x,x,x);
    printf("%d %#o %#x\n",x,x,x);*/
    //x = INT_MAX;
   // printf("%u\n",x); // unsigned int
   // long long b=1;
    /*unsigned long long c=24565456545;
    short d = 65 ;
    printf("%lu %d\n",c,c);//long long; unsigned long long
    printf("%hd %#hx\n" ,d,d);//short int 
    printf("\n");
    char beep ='\v';
    printf("?%c?%c?",beep,beep);*/
    /*char c,d;
    scanf("%c%c",&c,&d);
    printf("%c%c",c,d);*/
    //bool fs ;
    
    /*int32_t me32; // me32 a 32-bit signed variable
me32 = 45933945;
printf("First, assume int32_t is int: ");
printf("me32 = %d\n", me32);
printf("Next, let's not make any assumptions.\n");
printf("Instead, use a \"macro\" from inttypes.h: ");
printf("me32 = %" PRId32 "\n", me32);
 double x =.12e15;
printf("%llf\n",x);
float a=1.0L,b=3.4e5f,sum = a*b;//a*b is stored as double , using (typically) 64 bits for each.
double news = 0xa.1fp10;
printf("news : %llf\n",news);*/
float aboat = 32000.0;
double abet = 2.14e9;
long double dip = 5.32e-5;
printf("%f can be written %e\n", aboat, aboat);
// next line requires C99 or later compliance
printf("And it's %a in hexadecimal, powers of 2 notation\n", aboat);
printf("%f can be written %e\n", abet, abet);
printf("%Lf can be written %Le\n", dip, dip);

size_t x = 50;
printf("Type int has a size of %zd bytes.\n", x);
printf("Type int has a size of %zd bytes.\n", sizeof(int));
printf("Type char has a size of %zd bytes.\n", sizeof(char));
printf("Type long has a size of %zd bytes linhaohao.\n", sizeof(long));
printf("Type long long has a size of %zd bytes.\n",
sizeof(long long));
printf("Type double has a size of %zd bytes.\n",
sizeof(double));
printf("my Type small long double has a size of %zd bytes.pig \n",
sizeof(long double));
printf("?\t");
printf("?\t");
printf("?\t");
}