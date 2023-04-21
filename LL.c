#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct NODE
{
    int data;
    struct NODE *next;
};
typedef struct NODE *node;
node head=NULL;
node tail=NULL;
node tail1=NULL;
node insert(int c)
{
    node newnode=(node)malloc(sizeof(struct NODE));
    if(newnode==NULL)
    {
        printf("\nNode not created");
        exit(0);
    }
    newnode->data=c;
    newnode->next=NULL;
    return newnode;
}
void read(FILE *fp)
{
    int c; node cur;
    int n;
    printf("\nEnter range: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&c);
        if(i==0)
        {
            head=insert(c);
            tail=head;
        }
        else
        {
            tail1=insert(c);
            tail->next=tail1;
            tail=tail->next;
        }
    }
}
void rad(FILE *fp)
{
    for(int i=0;i<100;i++)
    {
        fprintf(fp,"%d ",rand()%100);
    }
}
void disp()
{
    if(head==NULL)
    {
        printf("\nEmpty..");
        return ;
    }
    node temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void sort()
{
    node cur=head,temp=NULL,temp1=head;
    while(cur->next!=NULL)
    {
        while(temp1->next!=NULL)
        {
            if(temp1->data>temp1->next->data)
            {
                int temp=temp1->data;
                temp1->data=temp1->next->data;
                temp1->next->data=temp;
            }
            temp1=temp1->next;
        }
        cur=cur->next;
        temp1=head;
    }
}
int main()
{
    FILE *fp;
    time_t t1,t2,t;
    fp=fopen("LL.txt","w");
    if(fp==NULL)
    {
        printf("\nFile not created.");
        exit(0);
    }
    rad(fp);
    fclose(fp);
    fp=fopen("LL.txt","r");
    read(fp);
    fclose(fp);
    t1=time(NULL);
    sort();
    t2=time(NULL);
    //printf("\nSorted: \n");
    //disp();
    t=t2-t1;
    printf("\nTime Taken: %ld",t);
    return 0;
}