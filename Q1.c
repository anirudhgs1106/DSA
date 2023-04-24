#include <stdio.h>
#include <stdlib.h>
//The function sorts an array of integers in ascending orders using the bubble sort
void sort(int a[],int m) //Parameter 'a' is an integer array that needs to be sorted and 'm' represent the size of array 'a[]'
{
    //The loop is used in the bubble sort to compare adjacent elements of the array and swap them if they are in the wrong order. 
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<m-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=0;  //This variable is used to temporarily store values of an element during swapping process
                temp=a[j];  //The value of 'a[j]' is temporarily stored in 'temp' so that it can be assigned to 'a[j+1]'  
                a[j]=a[j+1];  //and the value of 'a[j+1]' can be assigned to 'a[j]'
                a[j+1]=temp;
            }
        }
    }
}
//The function reads integers from a file to array, sorts and writes the sorted array to another file
int main()
{
    int arr[10],arr1[10],n,m;
    FILE *fp;  //Declaration of file pointer named fp
    fp=fopen("eval.txt","r");  //Opening of file in read mode
    if(fp==NULL)
    {
        printf("\nFile not opened.");
        exit(0);
    }
    while(!feof(fp))  //feof indicates the end of file
    {
        fscanf(fp,"%d",&arr[n]); //Read from file and write's to array
        n++;
    }
    printf("\nArray: ");  //This code is printing the elements of array. 
    for(int i=0;i<n;i++)  //'n' is the number of elements in the array
    {
        printf("%d ",arr[i]);
    }
    fclose(fp);  //Closing of file 
    m=arr[0];  //Assining first element of arr to variable 'm'
    int a[m];  //Declaring an integer array named 'a' with a size of 'm'
    int k=0;
    for(int i=1;i<m+1;i++)
    {
        a[k]=arr[i];
        k++;
    }
    printf("\nArray 2: ");  
    for(int i=0;i<m;i++)  //'m' is the number of elements present in the file
    {
        printf("%d ",a[i]);  //Printing the elements of array
    }
    printf("\n");
    sort(a,m);  //Calling the function and passing the integer array 'a' and its size 'm' as arguments
    for(int i=0;i<m;i++)
    {
        printf("%d ",a[i]);
    }
    fp=fopen("eval1.txt","w");  //Opening of file in write mode
    if(fp==NULL)
    {
        printf("\nFile not opened.");
        exit(0);
    }
    for(int i=0;i<m;i++)  //The sorted elements of integer array 'a' is written into file using for loop  
    {
        fprintf(fp,"%d ",a[i]);  //fprintf function used to write each elements to file 
    }
    fclose(fp);  //Closing of file
    return 0;  //The function 'main()'is returning an integer value of 0
}