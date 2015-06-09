#include <stdio.h>

int A,B;

int f(int n)
{
    if(1 == n || 2 == n)
    {
        printf("1 ");
        return 1;
    }
    
    printf("%d ",(A*f(n - 1) + B * f(n - 2)) % 7);
    return (A * f(n - 1) + B * f(n - 2)) % 7;
        
}

int main(int argc,char *argv[])
{
    int n;

    while(scanf("%d%d%d",&A,&B,&n) != EOF && (A || B || n))
    {
        if(A < 1 || B < 1 || A > 1000 || B > 1000)
        {
            return -1;
        }
        
        if(n < 1 || n > 100000000)
        {
            return -1;
        }
        
        printf("f(n) = %d\n",f(n));
    }

    return 0;
}
