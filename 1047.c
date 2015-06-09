/*
 * acm for 1047
 *
 * */

#include <stdio.h>
#include <string.h>

#define MAXLEN  100

/*
 * reversion the data
 * */
void reveData(char *str)
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
    char veryLongInteger[MAXLEN][MAXLEN],answerLongInteger[MAXLEN][MAXLEN+1];
    char temp[MAXLEN+1];
    int n,m,i,j,sum,cnt,tempCnt,addValueFlag;
    unsigned int maxLen,k;

    while(scanf("%d",&n) != EOF)    //n blocks
    {
        //printf("\n");
        memset(answerLongInteger,0,sizeof(answerLongInteger));

        for(i = 0;i < n;i++)
        {
            /*init*/
            memset(veryLongInteger,0,sizeof(veryLongInteger));
            memset(temp,0,sizeof(temp));
            cnt = 0;
            sum = 0;
            maxLen = 0;
            tempCnt = 0;
            addValueFlag = 0;
            temp[0] = '0';

            /*input long integer*/
            for(j = 0;j < MAXLEN;j++)
            {
               //auto '\0' of scanf 
               scanf("%s",veryLongInteger[j]);
               if('0' == veryLongInteger[j][0])
               {
                    break;
               }
                reveData(veryLongInteger[j]);
                ++cnt;
                
                //printf("strlen(veryLongInteger[%d]) = %d\n",j,strlen(veryLongInteger[j]));
                if(strlen(veryLongInteger[j]) > maxLen)
                {
                    maxLen = strlen(veryLongInteger[j]);
                }
            }

            /*calculate*/
            //printf("maxLen = %d,cnt = %d,start calculate\n",maxLen,cnt);
            for(k = 0;k < maxLen; k++)
            {
                sum = 0;
                for(m = 0;m < cnt;m++)
                {
                    //printf("veryLongInteger[%d][%d] = %d\n",m,k,veryLongInteger[m][k]);
                    if(veryLongInteger[m][k] != '\0')
                    {
                        sum += veryLongInteger[m][k] - '0';
                    }
                }

                sum += addValueFlag;

                /*
                 *  process the sum
                 * */
                //printf("sum = %d\n",sum);
                
                if(sum >= 10)
                {
                    temp[tempCnt++] = sum%10 + '0';
                    addValueFlag = sum/10;
                }
                else
                {
                    temp[tempCnt++] = sum + '0';
                    addValueFlag = 0;
                }

                if(k == maxLen - 1)
                {
                    if(addValueFlag > 0)
                    {
                        temp[tempCnt] = addValueFlag + '0';
                    }
                }
            }

            reveData(temp);
            printf("%s\n",temp);
            
          //  memcpy(answerLongInteger[i],temp,strlen(temp));

            if(i != n - 1)
            {
                printf("\n");
            }

        }//end for


        /*
         * output
         * */
    /*    
        for(i = 0;i < n; i++)
        {
            //printf("i = %d,exec\n",i);
            printf("%s\n",answerLongInteger[i]);
            
            if(i != n - 1)
            {
                printf("\n");
            }
        }
    */
        
    }//end while


    return 0;
}
