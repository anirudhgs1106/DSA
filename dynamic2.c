//Count number of ways to cover a distance
#include <stdio.h>
#include <stdlib.h>
int distance(int n)
{
    int no[n+1];
    no[0]=1;
    if(n>=1)
        no[1]=1;
    if(n>=2)
        no[2]=2;
    for(int i=3;i<=n;i++)
    {
        no[i]=no[i-1]+no[i-2]+no[i-3];
    }
    return no[n];
}
int main()
{
    int n,c;
    printf("\nEnter distance: ");
    scanf("%d",&n);
    c=distance(n);
    printf("\nNumber of ways are : %d",c);
    return n;
}