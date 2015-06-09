#include <stdio.h>
#include <string.h>

int f(int n)
{
    int temp;
    int sum = 0;

    while(n)
    {
        temp = n % 10;
        sum += temp;
        n = n / 10;
    }

    if(sum >= 10)
    {
        f(sum);
    }
    else
    {
        return sum;
    }

}

int main(int argc,char *argv[])
{
    char str[1000];
    int i,j,sum;

    while(1)
    {
        sum = 0;
        memset(str,0,strlen(str));

        scanf("%s",str);

        if(str[0] == '0')
        {
            break;
        }
 

        for(i = 0;i <= (int)(strlen(str) - 1);i++)
        {
            sum += (str[i] - '0');
        }

        printf("%d\n",f(sum));
    }

    return 0;
}
