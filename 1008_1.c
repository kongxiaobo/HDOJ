#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    int n,i,sum;
    int a[100];

    while(scanf("%d",&n) != EOF && n)
    {
         memset(a,0,100);
         sum = 0;

         for(i = 0;i < n;i++)
         {
            scanf("%d",&a[i]); 
         }


         for(i = 0;i < n - 1;i++)
         {
            if(a[i + 1] > a[i])
            {
                sum += (a[i + 1] - a[i]) * 6;
            }
            else
            {
                sum += (a[i] - a[i + 1]) * 4; 
            }
         }

         printf("%d\n",sum + n*5 + a[0]*6);

    }

    return 0;
}
