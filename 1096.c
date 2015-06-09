#include <stdio.h>

int main(int argc,char *argv[])
{
    int a,sum,n,m,i,j;
    
    while(scanf("%d",&n) == 1)
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
            
            if(i == n-1)
            {
                printf("%d\n",sum);
            }
            else
            {
                printf("%d\n\n",sum);
            }
        }
    }

    return 0;
}
