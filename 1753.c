#include <stdio.h>
#include <string.h>

#define NUM 400

int main(int argc,char *argv[])
{
    char A[NUM],B[NUM],temp[NUM + 1],tempA[NUM],tempB[NUM];
    char *locPoint_A = NULL;
    char *locPoint_B = NULL;

    int len_A,len_B,max,add_one_flag = 0,i,j,sum,cnt,nextFlag,viewFlag,pointIndex,firstOpen;
    memset(A,0,NUM);
    memset(B,0,NUM);

    while(scanf("%s%s",A,B) != EOF)
    {
start:
         cnt = 0;
         j = 0;
         firstOpen = 0;
         add_one_flag = 0;
         viewFlag = 0;
         nextFlag = 0;
         memset(tempA,'0',NUM);
         memset(tempB,'0',NUM);
         memset(temp,'0',NUM + 1);

         len_A = strlen(A);
         len_B = strlen(B);

         locPoint_A = strchr(A,'.');
         if(NULL == locPoint_A)
         {
            A[len_A] = '.'; 
            A[len_A + 1] = '0';
            nextFlag = 1;
         }

         locPoint_B = strchr(B,'.');
        if(NULL == locPoint_B)
        {
            B[len_B] = '.'; 
            B[len_B + 1] = '0';
            nextFlag = 1;
        }

        if(1 == nextFlag)
        {
            goto start;
        }

        /*float*/ 
        max = len_A - (locPoint_A - A) - 1;
        if(len_B - (locPoint_B - B) - 1 > max)
        {
            max = len_B - (locPoint_B - B) - 1;
        }
         
        memmove(tempA,locPoint_A + 1,len_A - (locPoint_A - A) - 1);
        memmove(tempB,locPoint_B + 1,len_B - (locPoint_B - B) - 1);
        
        for(i = 0;i < max;i++)
        {
           sum = (tempA[max - 1 - i] - '0') + (tempB[max - 1 - i] - '0') + add_one_flag;
           if(sum % 10 > 0 && 0 == firstOpen)
           {
                viewFlag = 1;
                j = i;
                firstOpen = 1;
           }

           if(sum >= 10) 
           {
                temp[NUM - i] = sum % 10 + '0';
                add_one_flag = 1;
           }
           else
           {
                temp[NUM - i] = sum + '0';
                add_one_flag = 0;
           }
           ++cnt;
        }

        temp[NUM - cnt] = '.';
        ++cnt;
        
        if(1 == viewFlag)
        {
            pointIndex = NUM - j;
        }
        else
        {
            pointIndex = NUM - cnt;
        }

        
        
        /*dec*/
        memset(tempA,'0',NUM);
        memset(tempB,'0',NUM);

        max = locPoint_A - A;
        if(locPoint_B - B > max)
        {
            max = locPoint_B - B;
        }
        
        memmove(tempA + NUM - (locPoint_A - A),A,locPoint_A - A);
        memmove(tempB + NUM - (locPoint_B - B),B,locPoint_B - B);
        
        for(i = 0;i < max;i++)
        {
             sum = (tempA[NUM - i - 1] - '0') + (tempB[NUM - i - 1] - '0') + add_one_flag;
             if(sum >= 10)
             {
                temp[NUM - cnt] = sum%10 + '0';
                add_one_flag = 1;
             }
             else
             {
                 temp[NUM - cnt] = sum + '0';
                 add_one_flag = 0;
             }
             ++cnt;
        }

        if(1 == add_one_flag)
        {
            temp[NUM - cnt] = '1';
            ++cnt;
        }

        for(i = NUM - cnt + 1;i <= NUM;i++)
        {
            if(i > pointIndex)
            {
                ;
            }
            else
            {
                printf("%c",temp[i]);
            }
        }
        printf("\n");

        memset(A,0,NUM);
        memset(B,0,NUM);
    }

    return 0;
}

