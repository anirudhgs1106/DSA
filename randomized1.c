//Randomized Binary Search in Sorted array
#include <stdio.h>
#include <stdlib.h>
int random_(int lw,int up)
{
    int c;
    c=lw+rand()%(up-lw+1);
    return c;
}
int search(int arr[],int lw,int up,int m)
{
    if(lw<=up)
    {
        int mid=random_(lw,up);
        if(arr[mid]==m)
            return mid+1;
        if(arr[mid]>m)
            return search(arr,lw,mid-1,m);
        return search(arr,mid+1,up,m);
    }
    return -1;
}
int main()
{
    int arr[]={9,10,20,33,56,67,78,98,101,199};
    int n=sizeof(arr)/sizeof(arr[0]);
    int m;
    printf("\nEnter number to be searched: ");
    scanf("%d",&m);
    int k=search(arr,0,n-1,m);
    if(k==-1)
        printf("\nNot found %d",m);
    else
        printf("\nFound %d at %d",m,k);
    return 0;
}