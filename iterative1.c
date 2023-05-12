//Largest number in Array
#include <stdio.h>
int largest(int arr[],int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    return max;
}
int main()
{
    int l;
    int arr[10]={10,23,1,0,221,33,100,88,7,56};
    int n=sizeof(arr)/sizeof(arr[0]);
    l=largest(arr,n);
    printf("\nLargest number in an Array is %d ",l);
    return 0;
}