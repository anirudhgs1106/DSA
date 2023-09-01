//Matrix addition
#include <stdio.h>
#include <stdlib.h>
void disp(int c[2][2])
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}
void addition(int c[2][2],int a[2][2],int b[2][2])
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    disp(c);
}
int main()
{
    int a[2][2]={{1,2},{3,4}};
    int b[2][2]={{4,3},{2,1}};
    int c[2][2]={};
    addition(c,a,b);
    return 0;
}