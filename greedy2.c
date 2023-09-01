//Min and Max to buy all N candies
#include <stdio.h>
#include <stdlib.h>
void sort(int price[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(price[j]>price[j+1])
            {
                int temp=price[j];
                price[j]=price[j+1];
                price[j+1]=temp;
            }
        }
    }
}
void minimum(int price[],int k,int n)
{
    int min=0;
    for(int i=0;i<n;i++)
    {
        min=min+price[i];
        n=n-k;
    }
    printf("\nMin %d ",min);
}
void maximum(int price[],int k,int n)
{
    int max=0,m=0;
    for(int i=n-1;i>=m;i--)
    {
        max=max+price[i];
        m=m+k;
    }
    printf("\nMax %d ",max);
}
int main()
{
    int k;
    int price[]={5,1,2,10};
    int n=sizeof(price)/sizeof(price[0]);
    printf("%d ",n);
    printf("\nEnter ");
    scanf("%d",&k);
    sort(price,n);
    minimum(price,k,n);
    maximum(price,k,n);
    return 0;
}