#include <stdio.h>

int main(int argc,char *argv[])
{
    double r;
    while(scanf("%lf",&r) != EOF)
    {
        if(r < 0)
        {
            r = -r;
        }

        printf("%.2lf\n",r);
    }

    return 0;
}
