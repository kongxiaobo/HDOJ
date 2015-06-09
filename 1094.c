#include <stdio.h>

int main(int argc,char *argv[])
{
    int a,sum,n,i;
    
    while(scanf("%d",&n) != EOF)
    {        
        sum = 0;
        for(i = 0;i < n;i++)
        {
            scanf("%d",&a);
            sum += a;
        }
        printf("%d\n",sum);
    }

    return 0;
}
