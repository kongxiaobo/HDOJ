/*
 *  hdoj for 1715
 * */

#include <stdio.h>
#include <string.h>

#define VALUE_SIZE  1000

void reveValue(char *value)
{
    int strLen = strlen(value);
    int i;
    char temp;

    for(i = 0;i < strLen/2;i++)
    {
        temp = value[i];
        value[i] = value[strLen - i - 1];
        value[strLen - i - 1] = temp;
    }
}

/*
 * 两个数组相加
 * */
void TwoArraySum(char *valueA,char *valueB,char valueC[][VALUE_SIZE],int pos)
{   
    int maxLen,i,temp,addOneFlag = 0;
    maxLen = strlen(valueA) > strlen(valueB)?strlen(valueA):strlen(valueB);

    for(i = 0;i < maxLen;i++)
    {
        /*
         * 获得temp值
         *
         * */
       if(valueA[i] != '\0' && valueB[i] != '\0')
       {
            temp =  valueA[i] - '0' + valueB[i] - '0' + addOneFlag;
       }
       else
       {
            if(valueA[i] == '\0')
            {
                temp =  valueB[i] - '0' + addOneFlag;
            }
            else
            {
                temp =  valueA[i] - '0' + addOneFlag;
            }
       }

       /*
        * 对temp进行特殊处理
        * */
       if(temp >= 10)
       {
           valueC[pos][i] = temp % 10 + '0'; 
           addOneFlag = 1;
       }
       else
       {
           valueC[pos][i] = temp + '0';  
           addOneFlag = 0;
       }
    }
    
    if(1 == addOneFlag)
    {
        valueC[pos][maxLen] = '1';
    }

}

int main(int argc,char *argv[])
{
    int i,j,k,N,Pi;
    char fiboValue[VALUE_SIZE + 1][VALUE_SIZE];
    char evenValue[VALUE_SIZE];
    char oddValue[VALUE_SIZE];
    
    while(scanf("%d",&N) != EOF)
    {
        for(i = 0;i < N;i++)
        {
            scanf("%d",&Pi);

            if(Pi < 1 || Pi > 1000)
            {
                return -1; 
            }

            /*
             * 初始化二维数组
             *
             * */
            memset(fiboValue,0,sizeof(fiboValue));
            fiboValue[0][0] = '0';
            fiboValue[1][0] = '1';
            fiboValue[2][0] = '1';

            /*
             *  
             * calc the sum
             * */
            for(j = 3;j <= Pi;j++)
            {
                TwoArraySum(&(fiboValue[j - 2][0]),&(fiboValue[j - 1][0]),fiboValue,j);
            }

            /*
             * output value
             * */
            for(j = 1;j <= Pi;j++)
            {
                reveValue(fiboValue[j]);
                if(j == Pi)
                {
                    printf("%s\n",fiboValue[j]);      
                }
            }
        }
    }
    
    return 0;
}
