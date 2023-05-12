//Selecting random node form Singly Linked list
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct NODE 
{
    int a;
    struct NODE *next;
};
typedef struct NODE *node;
node getnode()
{
    node newn=(node)malloc(sizeof(struct NODE));
    newn->next=NULL;
    return newn;
}
node read(node head,int c)
{
    node newn=getnode();
    newn->a=c;
    if(head==NULL)
        return newn;
    node temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newn;
    return head;
}
void randomp(node head)
{
    if(head==NULL)
        return;
    srand(time(NULL)); //
    int key=head->a;
    node temp=head;
    for(int i=2;temp!=NULL;i++)
    {
        if(rand()%i==0)
            key=temp->a;
        temp=temp->next;
    }
    printf("\nRandomly selected: %d",key);
}
int main()
{
    node head=NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        head=read(head,c);
    }
    randomp(head);
    /*printf("\nDisplay: ");
    node temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->a);
        temp=temp->next;
    }*/
    return 0;
}