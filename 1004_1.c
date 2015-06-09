/*
 * accept
 *
 * */
#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    int n,i,j;
    char b_col[1000][16];
    int col_num[1000];
    int max_flag,max_i;
    
    while(scanf("%d",&n) != EOF && n)
    {
        memset(col_num,0,sizeof(col_num));//key code:memset(col_num,0,1000); wrong answer,1000 is wrong,int type
        max_flag = 0;
        max_i = 0;
        
        for(i = 0;i < n;i++)
        {
            scanf("%s",b_col[i]); 
        }

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
            }
        }

        printf("%s\n",b_col[max_i]);
    }

    return 0;
}
