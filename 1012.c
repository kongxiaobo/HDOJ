#include <stdio.h>

double xc(int n)
{
    int i;
    int temp = 1;

    for(i = 1;i<=n;i++)
    {
         temp = temp * i;
    }

    return 1.0/temp;
}

int main(int argc,char *argv[])
{
	int i,j;
    double sum;

    printf("n e\n");
    printf("- -----------\n");

	for(i = 0;i < 10;i++)
	{
        sum = 0.0;
        
        for(j = 0;j <= i;j++)
        {
            if(0 == j)
            {
                sum += 1;
            }
            else
            {
                sum += xc(j); 
            }
             
        }

        if(i <= 2)						//格式控制
        {
            printf("%d %g\n",i,sum);
        }
        else
        {
            printf("%d %.9g\n",i,sum);
        }
    }			

    return 0;
}
