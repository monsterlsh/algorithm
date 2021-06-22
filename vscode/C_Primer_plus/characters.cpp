#include <iostream>
#include<string.h>
#include<limits.h>
#include<float.h>
#define PRAISE "You are an extraordinary being."
#define ok =
#define PI 3.141593
int main()
{
    enum a{MON,Tue};
    const int MONTHS = 12;
    /* char name[40];
    FILE* path = tmpfile();
    fputs("Alan the",path);
    fgets(name, 40,path);
    std::cout << "Hello World!\n"<<name;*/

    /*char name[40];
    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %d__\b letters occupies %d__\b memory cells.\n",
           strlen(name), sizeof name);
    printf("The phrase of praise has %zd letters ",
           strlen(PRAISE));
    printf("and occupies %zd memory cells.\n", sizeof PRAISE);

    int buok ok 3;
    std::cout<<buok;
    std::cout<<INT_MAX<< FLT_MAX<<std::endl;*/
  /*  printf("Some number limits for this system:\n");
printf("Biggest int: %d\n", INT_MAX);
printf("Smallest long long: %lld\n", LLONG_MIN);
printf("One byte = %d bits on this system.\n", CHAR_BIT);
printf("Largest double: %e\n", DBL_MAX);
printf("Smallest normal float: %e\n", FLT_MIN);
printf("float precision = %d digits\n", FLT_DIG);
printf("float epsilon = %e\n", FLT_EPSILON);
float x = 0.0005000000014;
double b=5.23;
double c =5.00000;
printf("%.20llf %g %g",x,b,c);
std::cout<<std::endl<<std::endl;
int number = 7;
double pies = 12.75456465465;
int cost = 7800;
printf("The %d contestants ate %Lf berry pies.\n", number,
pies);
printf("The value of pi is %f.\n", PI);
printf("Farewell! thou art too dear for my possessing,\n");
printf("%c%d\n", '$', 2 * cost);
    return 0;*/
    /*int n = 1;
    double f =22.333;
    printf("*%06.5d*%06.2f**** ** ",n,f);
    printf("sss\n");
    float n1 = 3.0; double n2 = 3.0; long n3 = 2000000000; long n4 = 1234567890;printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);

printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
int c = printf("%d\n", n3, n4);
printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
std::cout<< sizeof(float)<<" "<< sizeof(long)<<" " <<sizeof(double)<<std::endl;
std::cout<<c<<std::endl;
printf("Here's another way to print a \
long string.\n");
printf("Here's the newest way to print a "
"long string.\n"); /* ANSI C */
/*printf("Hello, young lovers, wherever you are.");
printf("Hello, young " "lovers" ", wherever you are.");
printf("Hello, young lovers"
", wherever you are.");*/
unsigned width, precision;
int number = 256;
double weight = 242.5;
printf("Enter a field width:\n");
scanf("%d", &width);
printf("The number is :%*d:\n", width, number);
printf("Now enter a width and a precision:\n");
scanf("%d %d", &width, &precision);
printf("Weight = %*.*f\n", width, precision, weight);
printf("Done!\n");

}
