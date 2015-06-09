/*
 *Error:Overflow
 *
 * sample:if n == 50000,memory is overflow
 * */

#include <stdio.h>

int main(int argc,char *argv[])
{
    int n;
    
    while(scanf("%d",&n) != EOF)
    {
        printf("%d\n\n",n*(n + 1)/2);
    }
    
    return 0;
}













































































