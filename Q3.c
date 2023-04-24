#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//The function sorts an array of integers in ascending orders using the bubble sort
void sort(int b[],int m)  //Parameter 'b' is an integer array that needs to be sorted and 'm' represent the size of array 'b[]'
{
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<m-i-1;j++)
        {
            if(b[j]>b[j+1])
            {
                int temp=0;  //This variable is used to temporarily store values of an element during swapping process
                temp=b[j];  //The value of 'a[j]' is temporarily stored in 'temp' so that it can be assigned to 'a[j+1]'  
                b[j]=b[j+1];
                b[j+1]=temp;  //and the value of 'a[j+1]' can be assigned to 'a[j]'
            }
        }
    }
}
int main()
{
    int n,m;
    time_t t1,t2,t;
    FILE *fp;  //Declaration of file pointer named fp
    printf("\nEnter number of random elements:  ");  //Taking input from user to enter number of random elements to be generated
    scanf("%d",&n);
    int a[n];  //Declaring an integer array named 'a' with a size of 'n'
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;  //Generating random integers from 0 to 99 and assigning it to the i'th element of integer array 'a'
    }
    fp=fopen("test2.txt","w");  //Opening of file in write mode
    if(fp==NULL)
    {
        printf("\nFile not created");
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d ",a[i]);  //fprintf function used to write each elements to file 
    }
    fclose(fp);  //Closing of file 
    fp=fopen("test2.txt","r");  //Opening of file in read mode for sorting
    printf("\nEnter number to be sorted:  ");  //Taking input from user to enter number of elements to be sorted
    scanf("%d",&m);
    int b[m];  //Declaring an integer array named 'a' with a size of 'm'
    if(fp==NULL)
    {
        printf("\nFile not opened");
        exit(0);
    }
    for(int i=0;i<m;i++)
    {
        fscanf(fp,"%d",&b[i]);  //Reading an integer value from file and stroing it in the i'th element of integer array 'b[]'
    }
    fclose(fp);  //Closing of file 
    t1=time(NULL);  //Assigning the current time in sec to variable 't1'
    sort(b,m);  //Calling the function and passing the integer array 'b' and its size 'm' as arguments
    t2=time(NULL);  //Assigning the current time in sec to variable 't2'
    t=t2-t1;  //Time taken to sort the elements 
    printf("\nTime taken: %d",t);
    return 0;
}