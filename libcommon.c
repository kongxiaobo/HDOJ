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
