//Pattern Checking
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void pattern(char str[],char str1[])
{
    int i,j,k;
    int m=strlen(str);
    int n=strlen(str1);
    printf("%d %d",m,n);
    for(i=0;i<m-n;i++)
    {
        for(j=i,k=0;k<n && (str[j]==str1[k]);j++,k++);
        if(k==n)
            printf("\nPattern Match!");
    }
}
int main()
{
    char str[10]="silent";
    char str1[10]="let";
    pattern(str,str1);
    return 0;
}