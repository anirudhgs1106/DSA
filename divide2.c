//Binary search in Sorted array
#include <stdio.h>
#include <stdlib.h>
int search(int arr[],int lw,int up,int s)
{
    if(up>=lw)
    {
        int mid=(up+lw)/2;
        if(arr[mid]==s)
            return mid+1;
        else if(arr[mid]<s)
        {
            return search(arr,mid+1,up,s);
        }
        else
        {
            return search(arr,lw,mid-1,s);
        }
    }
    return -1;
}
int main()
{
    int arr[]={1,22,39,67,78,91,100,123,134,199};
    int n=sizeof(arr)/sizeof(arr[0]);
    int s;
    printf("\nEnter number to be searched: ");
    scanf("%d",&s);
    int k=search(arr,0,n-1,s);
    if(k==-1)
        printf("\nNot found!");
    else 
        printf("\nFound at %d",k);
    return 0;
}