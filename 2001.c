#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc,char *argv[])
{
    double x1,y1,x2,y2;

    while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2) != EOF)
    {
           //printf("%.2lf\n",sqrt(pow((double)(abs((int)(x1-x2))),2.0)+pow((double)(abs((int)(y1-y2))),2.0)));
           printf("%.2lf\n",sqrt(pow(x1-x2,2.0)+pow((y1-y2),2.0)));
    }

    return 0;
}
