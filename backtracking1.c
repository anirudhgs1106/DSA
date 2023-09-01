//Permutation of given string
#include <stdio.h>
#include <string.h>
void swaping(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
void per(char *s,int lw,int up)
{
    if(lw==up)
        printf("%s\n",s);
    else
    {
        for(int i=lw;i<=up;i++)
        {
            swaping((s+lw),(s+i));
            per(s,lw+1,up);
            swaping((s+lw),(s+i));
        }
    }
}
int main()
{
    char str[]="ANI";
    int n=strlen(str);
    per(str,0,n-1);
    return 0;
}