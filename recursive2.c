//Largest number in an Array
#include <stdio.h>
int largest(int arr[],int lw,int lr)
{
    int max;
    if(lw==lr)
    {
        return arr[lw];
    }
    else
    {
        max=largest(arr,lw+1,lr);
        if(arr[lw]>max)
            return arr[lw];
        else
            return max;
    }
}
int main()
{
    int l,lw=0,lr=9;
    int arr[10]={10,23,1,0,2,33,100,88,7,56};
    l=largest(arr,lw,lr);
    printf("\nLargest number in an Array is %d ",l);
    return 0;
}