//Travelling Sales program
#include <stdio.h>
#include <stdlib.h>
int cost=0;
void read(int a[10][10],int b[10],int n)
{
    printf("\nEnter cost: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
        b[i]=0;
    }
}
int path(int a[10][10],int b[10],int n,int m)
{
    int c=999;
    int min=999,min1;
    for(int i=0;i<n;i++)
    {
        if((a[m][i]!=0) && (b[i]==0))
        {
            if(a[m][i]<min)
            {
                min=a[i][0]+a[m][i];
                min1=a[m][i];
                c=i;
            }
        }
    }
    if(min!=999)
        cost=cost+min1;
    return c;
}
void minimum(int a[10][10],int b[10],int n,int m)
{
    b[m]=1;
    printf("%d ->",m+1);
    int x=path(a,b,n,m);
    if(x==999)
    {
        x=0;
        printf("%d",x+1);
        cost=cost+a[m][x];
        return ;
    }
    minimum(a,b,n,x);
}
int main()
{
    int a[10][10],b[10],n;
    printf("\nEnter number of cities: ");
    scanf("%d",&n);
    read(a,b,n);
    printf("\nPath is: ");
    minimum(a,b,n,0);
    printf("\nMinimum cost: %d",cost);
    return 0;
}