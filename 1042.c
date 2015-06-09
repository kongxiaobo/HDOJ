#include <stdio.h>

long f(int n)
{
    int i;
    long sum = 1;

    if(0 == n)
    {
        return 1;
    }

    for(i = 1;i <= n;i++)
    {
        sum = sum * i; 
    }

    return sum;
}

int main(int argc,char *argv[])
{   
    int N;

    while(scanf("%d",&N) != EOF && N >= 0 && N <= 10000)
    {
        printf("%ld\n",f(N));    
    }

    return 0;
}
