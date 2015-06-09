#include <stdio.h>
#include <string.h>

#define MAX_NUM 50000

int main(int argc,char *argv[])
{
    int i,j,N,cnt = 1,plus_one_flag,num;
    char temp[MAX_NUM];

    while(scanf("%d",&N) != EOF && N >= 0 && N <= 10000)
    {
        memset(temp,'0',sizeof(temp));      //memset(temp,0,sizeof(temp));
        temp[MAX_NUM - 1] = '1';
        cnt = 1;

        for(i = 2;i <= N;i++)
        {
            plus_one_flag = 0;

            for(j = 1;j <= cnt;j++)
            {
                num = i * (temp[MAX_NUM - j] - '0') + plus_one_flag;
                 
                if(num / 10 >= 1)
                {
                     plus_one_flag =  num / 10;
                     temp[MAX_NUM - j] = num % 10 + '0';
				     if(j == cnt)
                     {
                        ++cnt;
                     }
                }
                else
                {
                     temp[MAX_NUM - j] = num + '0';
                     plus_one_flag = 0;
                }
            }
        }

        for(i = MAX_NUM - cnt;i < MAX_NUM;i++)
        {
            printf("%c",temp[i]);
        }
        printf("\n");
    }

    return 0;
}
