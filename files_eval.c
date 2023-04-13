#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr[10],arr1[10],n,m;
    FILE *fp;
    fp=fopen("eval.txt","r");
    if(fp==NULL)
    {
        printf("\nFile not opened.");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%d",&arr[n]);
        n++;
    }
    printf("\nArray: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    fclose(fp);
    m=arr[0];
    printf("\n%d ",m);
    for(int i=0;i<m;i++)
    {
        arr1[i]=arr[i+1];
    }
    printf("\nArray 2: ");
    for(int i=0;i<m;i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\n");
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr1[j+1])
            {
                int temp=0;
                temp=arr1[j];
                arr1[j]=arr1[j+1];
                arr1[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr1[i]);
    }
    fp=fopen("eval1.txt","w");
    if(fp==NULL)
    {
        printf("\nFile not opened.");
        exit(0);
    }
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d ",arr1[i]);
    }
    fclose(fp);
    return 0;
}