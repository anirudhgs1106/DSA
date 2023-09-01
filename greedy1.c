//Calculate change of amount using smallest possible number of coins 
#include <stdio.h>
#include <stdlib.h>
#define max 100
void disp(int k,int sol[max])
{
    printf("\nCoins: ");
    for(int i=0;i<k;i++)
    {
        printf("%d ",sol[i]);
    }
}
void change(int sol[max],int n,int k)
{
    int sum=0;
    while(sum!=n)
    {
        sol[k]=5;
        k++;
        sum=sum+5;
        if(sum>n)
        {
            sum=sum-5;
            k=k-1;
            sum=sum+2;
            sol[k]=2;
            k++;
        }
        if(sum>n)
        {
            sum=sum-2;
            k=k-1;
            sum=sum+1;
            sol[k]=1;
            k++;
        }
    }
    disp(k,sol);
}
int main()
{
    int n,k=0;
    printf("\nEnter amount: ");
    scanf("%d",&n);
    printf("\nAvailable coins: \nRs 5\nRs 2\nRs 1\n");
    int sol[max]={0};
    change(sol,n,k);
    return 0;
}