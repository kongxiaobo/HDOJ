#include <stdio.h>

int f(int n)
{
    int temp;
    int sum = 0;

    while(n)
    {
        temp = n % 10;
        sum += temp;
        n = n / 10;
    }

    if(sum >= 10)
    {
        f(sum);
    }
    else
    {
        return sum;
    }

}

int main(int argc,char *argv[])
{
    int n;

    while(scanf("%d",&n) != EOF && n)
    {
        printf("%d\n",f(n));
    }
    
    return 0;
}
