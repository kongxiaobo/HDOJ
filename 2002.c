#include <stdio.h>
#include <math.h>
#define PI 3.1415927

int main(int argc,char *argv[])
{
    double r;

    while(scanf("%lf",&r) != EOF)
    {
        printf("%.3lf\n",4.0*PI*pow(r,3.0)/3.0);         
        
    }

    return 0;
}
