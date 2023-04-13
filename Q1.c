#include <stdio.h>
#include <stdlib.h>
void sort(int a[],int m)
{
    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<m-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=0;
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
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
    int a[m];
    printf("\n%d ",m);
    int k=0;
    for(int i=1;i<m+1;i++)
    {
        a[k]=arr[i];
        k++;
    }
    printf("\nArray 2: ");
    for(int i=0;i<m;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    sort(a,m);
    for(int i=0;i<m;i++)
    {
        printf("%d ",a[i]);
    }
    fp=fopen("eval1.txt","w");
    if(fp==NULL)
    {
        printf("\nFile not opened.");
        exit(0);
    }
    for(int i=0;i<m;i++)
    {
        fprintf(fp,"%d ",a[i]);
    }
    fclose(fp);
    return 0;
}