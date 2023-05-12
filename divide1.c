//Merge sort
#include <stdio.h>
#include <stdlib.h>
void merge1(int arr[],int lw,int mid,int up)
{
    int i,j,k;
    int n1=mid-lw+1;
    int n2=up-mid;
    int a[n1],b[n2];
    for(i=0;i<n1;i++)
    {
        a[i]=arr[lw+i];
    }
    for(j=0;j<n2;j++)
    {
        b[j]=arr[mid+1+j];
    }
    i=0;j=0;k=lw;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k]=a[i];
            i++;
        }
        else
        {
            arr[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        j++;
        k++;
    }
}
void merge(int arr[],int lw,int up)
{
    if(lw<up)
    {
        int mid=lw+(up-lw)/2;
        merge(arr,lw,mid);
        merge(arr,mid+1,up);
        merge1(arr,lw,mid,up);
    }
}
int main()
{
    int arr[]={2,14,0,44,6,56,101,76,81,33};
    int n=sizeof(arr)/sizeof(arr[0]);
    merge(arr,0,n-1);
    printf("Sorted: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}