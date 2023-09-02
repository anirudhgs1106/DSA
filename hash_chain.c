#include <stdio.h>
#include <stdlib.h>
#define table_size 10
struct HASH
{
    int data;
    struct HASH *next;
};
typedef struct HASH *hash;
hash array[table_size];
hash head=NULL;
int hashkey(int key)
{
    return key%table_size;
}
void insert(int key,int data)
{
    int index=hashkey(key);
    hash temp,newn;
    newn=(hash)malloc(sizeof(struct HASH));
    newn->next=NULL;
    newn->data=data;
    if(array[index]==NULL)
    {
        array[index]=newn;
    }
    else if(array[index]!=NULL)
    {
        temp=array[index];
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newn;
    }
}
void print()
{
    for(int i=0;i<table_size;i++)
    {
        hash temp=array[i];
        printf("\nHash[%d]-->",i);
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int n,data,key;
    printf("\nEnter n:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nEnter key:");
        scanf("%d",&key);
        printf("Enter data:");
        scanf("%d",&data);
        insert(key,data);
    }
    print();
    return 0;
}