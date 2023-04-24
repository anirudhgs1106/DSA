#include <stdio.h>
#include <stdlib.h>
void sort(int a[],int n,FILE *fp)  //Parameter 'a' is an integer array that needs to be sorted, 'm' represent the size of array 'a[]'
                                   //and 'fp' is pointer to a file where the sorted array will be written
{
    //The loop is used in the bubble sort to compare adjacent elements of the array and swap them if they are in the wrong order. 
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j< n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=0;  //This variable is used to temporarily store values of an element during swapping process
                temp=a[j];
                a[j]=a[j+1];  //The value of 'a[j]' is temporarily stored in 'temp' so that it can be assigned to 'a[j+1]'  
                a[j+1]=temp;  //and the value of 'a[j+1]' can be assigned to 'a[j]'
            }
        }
    }
    for(int i=0;i<n;i++)  //The sorted elements of integer array 'a' is written into file using for loop 
    {
        fprintf(fp,"%d ",a[i]);  //fprintf function used to write each elements to file 
    }
}
int main()
{
    int n;
    FILE *fp;  //Declaration of file pointer named fp
    fp=fopen("test.txt","w");  //Opening of file in write mode
    if(fp==NULL)
    {
        printf("\nFile not created.");
        exit(0);
    }
    printf("\nEnter number of elements:  ");  //Taking input from user to enter number of elements to be sorted
    scanf("%d",&n);
    int a[n];  //Declaring an integer array named 'a' with a size of 'n'
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;  //Generating random integers from 0 to 99 and assigning it to the i'th element of integer array 'a'
    }
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d ",a[i]);  //fprintf function used to write each elements to file 
    }
    fclose(fp);  //Closing of file 
    fp=fopen("test1.txt","w");  //Openeing file in write mode to write sorted elements 
    if(fp==NULL)
    {
        printf("\nFile not opened.");
        exit(0);
    }
    sort(a,n,fp);  //Calling the function and passing the integer array 'a' and its size 'n' as arguments along with file pointer 'fp'
    fclose(fp);  //Closing of file 
    return 0;
}