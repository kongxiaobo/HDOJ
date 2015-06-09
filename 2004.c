#include <stdio.h>

int main(int argc,char *argv[])
{
    int score;

    while(scanf("%d",&score) != EOF)
    {
        if(score < 0 || score > 100)
        {
            printf("Score is error!\n");
            continue;
        }
        else if(score >= 0 && score <= 59)
        {
            printf("E\n");
            continue;
        }
        else if(score >= 60 && score <= 69)
        {
            printf("D\n");
            continue;
        }
        else if(score >= 70 && score <= 79)
        {
            printf("C\n");
            continue;
        }
        else if(score >= 80 && score <= 89)
        {
            printf("B\n");
            continue;
        }
        else if(score >= 90 && score <= 100)
        {
            printf("A\n");
            continue;
        }
    }

    return 0;
}
