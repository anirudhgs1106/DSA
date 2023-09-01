//Middle element in Linked list
#include <stdio.h>
#include <stdlib.h>
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
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newn;
    return head;
}
/*void disp(node head)
{
    if(head==NULL)
    {
        printf("\nNo elements");
        return ;
    }
    node temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->a);
        temp=temp->next;
    }
    printf("\n");
}*/
void middle(node head)
{
    int c;
    node temp=head;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    c=c/2;
    temp=head;
    for(int i=0;i<c;i++)
    {
        temp=temp->next;
    }
    printf("\nMiddle element of linked list is %d .",temp->a);
}
int main()
{
    node head=NULL;
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        head=read(head,c);
    }
    //disp(head);
    middle(head);
    return 0;
}