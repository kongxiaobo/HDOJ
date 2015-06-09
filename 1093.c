#include <stdio.h>

int main(int argc,char *argv[])
{
    int a,sum,n,m,i,j;
    
    while(scanf("%d",&n) != EOF)
    {        
        for(i = 0;i < n;i++)
        {
            sum = 0;
            scanf("%d",&m);
            for(j = 0;j < m;j++)
            {
                scanf("%d",&a);
                sum += a;
            }
            
            printf("%d\n",sum);
        }
    }

    return 0;
}
