/**
 * time exceeded
 * 
 */

#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    int n,i,j;
    char b_col[1000][15];
    short col_num[1000];
    short max_flag,max_i;
    
    do
    {
        scanf("%d",&n);
        if(0 == n)
        {
            continue;
        }

        memset(col_num,0,1000);
        max_flag = 0;
        
        /*
         *1.input
         */
        for(i = 0;i < n;i++)
        {
            scanf("%s",b_col[i]); 
        }

        /*
         *2.process
         * */
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < n;j++)
            {
                if(0 == strcmp(b_col[i],b_col[j]))
                {
                    col_num[i]++;     
                }
            }
        }
        
        for(i = 0;i < n;i++)
        {
            if(col_num[i] > max_flag)
            {
                max_flag = col_num[i];
                max_i = i;
                if(max_flag >= n/2)
                {
                    break;
                }
            }
        }

        printf("%s\n",b_col[max_i]);
        
    
    }while(n>=0 && n<=1000);

    return 0;
}
