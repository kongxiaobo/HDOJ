#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    int t,i,j,k,a_len,b_len,larger_num,temp1,temp2,count,plus_one_flag;
    char a[20][1000];
    char b[20][1000];
    char temp[1000];
    char sum[1000];

    scanf("%d",&t);
    if(t < 1 || t > 20)
    {
        return -1;
    }

    /* 
     * 1. input integers number 
     * */
    for(i = 0;i < t;i++)
    {
       scanf("%s%s",a[i],b[i]);     
    }

    /*
     *2. process this numbers
     * */
    for(i = 0;i < t;i++)
    {
        a_len = strlen(a[i]);
        b_len = strlen(b[i]);
        plus_one_flag = 0;
        count = 998;
        memset(temp,'0',1000);
        memset(sum,0,1000);

        if(a_len >= b_len)
        {
            larger_num = a_len;
            
            strncpy(temp + a_len - b_len,b[i],b_len);
        
            for(j = larger_num - 1;j >= 0;j--)
            {
                temp1 = a[i][j] - '0' + plus_one_flag;
                temp2 = temp[j] - '0';
            
                if(temp1 + temp2 < 10)
                {
                    sum[count--] = temp1 + temp2 + '0';
                    plus_one_flag = 0;
                }
                else
                {
                    sum[count--] = (temp1 + temp2)%10 + '0';
                    plus_one_flag = 1;
                    if(j == 0)
                    {
                       sum[count] = '1'; 
                    }
                }
            }

            if(sum[998 - a_len] == '\0')
            {
                printf("Case %d:\n",i+1);
                printf("%s + %s = %s",a[i],b[i],sum + 999 - a_len);
            }
            else
            {
                printf("Case %d:\n",i+1);
                printf("%s + %s = %s",a[i],b[i],sum + 998 - a_len);
            }
        }
        else
        {
            larger_num = b_len;
            strncpy(temp + b_len - a_len,a[i],a_len);
            
            for(j = larger_num - 1;j >= 0;j--)
            {
                temp1 = b[i][j] - '0' + plus_one_flag;
                temp2 = temp[j] - '0';
            
                if(temp1 + temp2 < 10)
                {
                    sum[count--] = temp1 + temp2 + '0';
                    plus_one_flag = 0;
                }
                else
                {
                    sum[count--] = (temp1 + temp2)%10 + '0';
                    plus_one_flag = 1;
                    if(j == 0)
                    {
                       sum[count] = '1'; 
                    }
                }
            }

            if(sum[998 - b_len] == '\0')
            {
                printf("Case %d:\n",i+1);
                printf("%s + %s = %s",a[i],b[i],sum + 999 - b_len);
            }
            else
            {
                printf("Case %d:\n",i+1);
                printf("%s + %s = %s",a[i],b[i],sum + 998 - b_len);
            }
            

        }
        
        if(i == t - 1)
        {
            printf("\n");
        }
        else
        {
            printf("\n\n");
        }
    }


    return 0;
}
