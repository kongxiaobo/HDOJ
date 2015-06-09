#include <stdio.h>

int main(int argc,char *argv[])
{
    int a,b,i;

    while(scanf("%d%d",&a,&b) != EOF && (a>0 && a <= 1000 && b > 0 && b <= 1000))
    {
        for(i = a;i <= a*b;i++)
        {
            if((0 == i % a) && (0 == i % b))
            {
                printf("%d\n",i);
                break;
            }
        }
    
    }

    return 0;
}
