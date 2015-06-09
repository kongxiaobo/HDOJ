#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[])
{
    char s[10] = "12345.678";
    char *p = NULL;
    p = strchr(s,'.');

    printf("%s,%d\n",p,p - s);

    return 0;
}
