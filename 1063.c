#include <stdio.h>
#include <string.h>
#include <math.h>

#define LEN 9
#define MAXLEN 1000
#define ZERO 0
#define LINENUMBER 5

/*
 *  sum
 * */
void Sum(char *sumBuf,char buf[][MAXLEN],int num,int colNum)
{
    printf("%s,num = %d,colNum = %d\n",__func__,num,colNum);
    int sum = 0;
    int addValue = 0;
    int i,j;

    for(j = 0;j < colNum;j++)
    {
        sum = 0;
        for(i = 0;i < num ;i++)
        {
            if(buf[i][j] != '\0')
            {
                sum += buf[i][j] - '0';
            }
        }

        sum += addValue;

        printf("sum = %d\n",sum);

        if(sum >= 10)
        {
            sumBuf[j] = sum % 10 + '0';
            addValue = sum / 10;
        }
        else
        {
            //if(0 == sum)
           // {
            //    continue;
           // }
            sumBuf[j] = sum + '0';
            addValue = 0;
        }
    }

    if(addValue > 0)
    {
        sumBuf[j] = addValue;
    }
}

/*
 * reversion the data
 * */
void ReveData(char *str)
{
    char *start = str;
    int len = strlen(str); 
    char *end = start + strlen(str) - 1;
    char temp;

    while(start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(int argc,char *argv[])
{
     double R;
     int tempR;
     int n,m,i,j,k,temp,addValue,exactValueLen,valueLen,answerValueLen,exactValueLenSum = 0;
     char valueNoPoint[LEN],value[LEN],answerValue[MAXLEN],tempValue[LINENUMBER][MAXLEN],*pPoint = NULL;

     while(scanf("%lf %d",&R,&n) != EOF)
     {
        if(R <= 0.0 || R >= 99.999 || n <= 0 || n > 25)
        {
            continue;
        }

        printf("R = %.3f \n",R);    // wrong when no 3 

        memset(value,ZERO,sizeof(value));
        memset(valueNoPoint,ZERO,sizeof(value));
        memset(answerValue,ZERO,sizeof(answerValue));
        memset(tempValue,ZERO,sizeof(tempValue));
        exactValueLenSum = 0;
        addValue = 0;

        answerValue[0] = '1'; 
        //answerValueLen =  strlen(answerValue);
        //printf("strlen(answerValue) = %d\n",answerValueLen);
        
        sprintf(value,"%.3f",R);
        printf("value = %s\n",value);
        valueLen = strlen(value); 
        printf("strlen(value) = %d\n",strlen(value));

        //get the len of after the character '.'
        pPoint = strchr(value,'.');
        exactValueLen = strlen(pPoint) - 1;
        printf("exactValueLen = %d\n",exactValueLen);

        exactValueLenSum = exactValueLen * n;
        printf("exactValueLenSum = %d\n\n",exactValueLenSum);

        //reveData(value);
        //printf("2 value = %s\n",value);

        printf("n = %d\n",n);
        /*
         *  process
         * */
        for(i = 0;i < n;i++)            //cnt
        {
            answerValueLen =  strlen(answerValue);
            printf("strlen(answerValue) = %d\n",answerValueLen);
            printf("answerValue = %s\n",answerValue);
            /*
             * process the real number
             * */ 
            if(exactValueLen > 0)
            {
                printf("R = %f\n",R);
                tempR = R*pow(10.0,exactValueLen);			//
                printf("tempR = %d\n",tempR);
                sprintf(valueNoPoint,"%d",tempR);
                ReveData(valueNoPoint);
                printf("valueNoPoint = %s\n",valueNoPoint);
            }

            printf("answerValueLen = %d\n",answerValueLen);
            for(j = 0;j < answerValueLen;j++)
            {
                addValue = 0;
                for(m = 0;m < j;m++)
                {
                    tempValue[j][m] = '0';
                }

                for(k = 0;k < valueLen - 1;k++)
                {
                    temp =  (valueNoPoint[k] - '0') * (answerValue[j] - '0') + addValue; 

                    if(temp >= 10)
                    {
                        tempValue[j][k + j] =  temp%10 + '0';       //k -> k+j
                        addValue = temp/10;
                    }
                    else
                    {
                        tempValue[j][k + j] =  temp + '0';
                        addValue = 0;
                    }

                    printf("tempValue[%d][%d] = %c\n",j,k + j,tempValue[j][k + j]);
                }

                if(addValue > 0)
                {
                    tempValue[j][valueLen - 1 + j] = addValue + '0';  
                    printf("tempValue[%d][%d] = %c\n",j,valueLen - 1 + j,tempValue[j][valueLen - 1 + j]);
                }

                printf("test:tempValue[%d] = %s\n",j,tempValue[j]);
                printf("test:strlen(tempValue[%d]) = %d\n",j,strlen(tempValue[j]));
                
            }
                
                Sum(answerValue,tempValue,answerValueLen,strlen(valueNoPoint) + answerValueLen + 2);//col num is wrong ??
                //ReveData(answerValue);
                printf("test:answerValue = %s\n",answerValue);

        }

#if 0
        /*output process*/
        for(i = 0;i < exactValueLenSum;i++)
        {


        }
#endif
     }

     return 0;
}
