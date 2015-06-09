#include <stdio.h>

int main(int argc,char *argv[])
{
    char a,b,c;
    char temp;

    while(scanf("%c%c%c",&a,&b,&c) != EOF)
    {
        getchar();
        
        if(a > b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        
        if(a > c)
        {
            temp = a;
            a = c;
            c = temp;
           
        }
            
        if(b > c)
        {
            temp = b;
            b = c;
            c = temp;
        }

        printf("%c %c %c\n",a,b,c);

    }
    return 0;
}
