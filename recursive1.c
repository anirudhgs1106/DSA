//Reverse a String
#include <stdio.h>
void r_string(char *str)
{
    if(*str)
    {
        r_string(str+1);
        printf("%c",*str);
    }
}
int main()
{
    char c[]="Anirudh";
    r_string(c);
    printf("\n");
    return 0;
}