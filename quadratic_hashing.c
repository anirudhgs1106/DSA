#include <stdio.h>
#include <stdlib.h>
#define table_size 10
struct HASH 
{
    int data,key;
};
typedef struct HASH *hashing;
struct HASH *array;
int hashkey(int key)
{
    return key%table_size;
}
void insert(int data,int key)
{
    int index=hashkey(key);
    if(array[index].key==0)
    {
        array[index].key=key;
        array[index].data=data;
    }
    else
    {
        int i=0;
        while(array[(index+(i*i))%table_size].key!=0)
            i++;
        array[(index+(i*i)%table_size)].key=key;
        array[(index+(i*i)%table_size)].data=data;
    }
}
void initial()
{
    array=(hashing)malloc(sizeof(struct HASH));
    for(int i=0;i<table_size;i++)
    {
        array[i].key=0;
        array[i].data=0;
    }
}
void display(int data,int key)
{
    for(int i=0;i<table_size;i++)
    {
        if(array[i].key==0)
            printf("\nArray[%d] = /",i);
        else
            printf("\nKey : %d Array[%d] : %d ",array[i].key,i,array[i].data);
    }
}
int main()
{
    initial();
    int n,data,key;
    printf("\nEnter number: ");
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter key: ");
        scanf("%d",&key);
        printf("\nEnter data: ");
        scanf("%d",&data);
        insert(data,key);
    }
    display(data,key);
    return 0;
}