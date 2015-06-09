#include <stdio.h>
#include <math.h>

int main(int argc,char *argv[])
{
	double m,a;
	int t,i,n,k;
    long long b;

	scanf("%d",&t);

	for(i = 0;i < t;i++)
	{
		scanf("%d",&n);
        m = n * log10(n);
        b = (long long)m;
        a = m - b;
        k = (int)pow(10.0,a);
        printf("%d\n",k);
	}
	
			
	return 0;
}
