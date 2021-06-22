include <stdio.h>
#include <ctype.h>

const int nmon = 12;

double Myscan()
{
	int t;
	int power = 1;
	double *n = 0.0;

	while ((t=getchar()) != EOF && isdigit(t))
		*n = *n * 10 + t - '0';
	if (t=='.')
	{
		while ((t=getchar()) != EOF && isdigit(t))
		{
			*n = *n * 10 + t- '0';
			power *= 10;
		}
	}
	return *n / power;
}

int main()
{
	int i;
	double sum = 0;

	for (i=1; i<=nmon; i++)
		sum += Myscan();
	printf("$%.2lf\n", sum/12);
	return 0;
}
