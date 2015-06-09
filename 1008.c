#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    int n,i,j = 0,max,min,count = 0,flag = 0,repCount,sum;
    int a[100];
    int b[100];
    memset(b,0,100);

    while(scanf("%d",&n) != EOF && n)
    {
         memset(a,0,100);
         flag = 0;
         //repCount = 0;
         sum = 0;

         for(i = 0;i < n;i++)
         {
            scanf("%d",&a[i]); 

            if(0 == i)
            {
                min = max = a[i];
            }
            
            if(a[i] > max)
            {
                max = a[i];
            }
            
            if(a[i] < min)
            {
                min = a[i];
            }
         }

         for(i = 0;i < n - 1;i++)
         {
            if(a[i + 1] < a[i])
            {
                flag = 1;
            }
/*
            else if((a[i+1] == a[i]) && i != n-1)
            {
                 repCount++;
            }
*/         
         }
        
         if(1 == flag)
         {
            //b[j++] = max * 6 + (max - min) * 4 + (n - repCount) * 5;
            sum = max * 6 + (max - min) * 4 + n * 5;
         }
         else
         {
             //b[j++] = max * 6 + (n - repCount) * 5;
             sum = max * 6 + n * 5;
         }

         //count++;
         printf("%d\n",sum);
        
    }

   /* 
    for(i = 0;i < count;i++)
    {
         printf("%d\n",b[i]);
    }
    */

    return 0;
}
