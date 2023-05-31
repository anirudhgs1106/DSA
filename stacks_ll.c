#include <stdio.h>
#include <stdlib.h>
struct STACK
{
    int no;
    struct STACK *top;
};
typedef struct STACK *st;
void updated(st head)  //Function to update the "stack.txt" file 
{
    FILE *fp2;
    fp2=fopen("stack.txt","w");  
    st temp=head;
    if(head==NULL)
        fprintf(fp2,"%d ",0);
    while(temp!=NULL)
    {
        fprintf(fp2,"%d ",temp->no);  //Writing the stack elements into the file
        temp=temp->top;
    }
    fclose(fp2);
}
st getnode(int x)
{
    st newn=(st)malloc(sizeof(struct STACK));  //Creating new node for a stack with a given value
    newn->no=x;
    newn->top=NULL;
    return newn;
}
st push(st head,FILE *fp)
{
    char p[]="push";
    FILE *fp3;
    fp3=fopen("log.txt","a");
    fprintf(fp3,"%s\n",p);  //Appending the "log.txt" with "push" i.e. operation being performed
    fclose(fp3);
    int c;
    fscanf(fp,"%d",&c);
    FILE *fp1;
    fp1=fopen("push.txt","a");
    fprintf(fp1,"%d ",c);  //Appending the pushed element into file
    fclose(fp1);
    st newn=getnode(c);
    if(head==NULL) 
        return newn;
    st temp=head;
    while(temp->top!=NULL)  //Traverse "temp" till rear
    {
        temp=temp->top;
    }
    temp->top=newn;  //Pushes new element to the rear of linked list
    return head;
}
st pop(st head)
{
    char p[]="pop";
    FILE *fp3,*fp1;
    fp1=fopen("pop.txt","a");
    fp3=fopen("log.txt","a");
    fprintf(fp3,"%s\n",p);  //Appending the "log.txt" with "pop" i.e. operation being performed
    fclose(fp3);
    if(head==NULL)
    {
        printf("\nStack underflow");
        return 0;
    }
    st prev,cur=head;
    if(head->top==NULL)
    {
        fprintf(fp1,"%d ",head->no);  //Appending the pushed element into file
        free(head);
        fclose(fp1);
        return NULL;
    }
    while(cur->top!=NULL)
    {
        prev=cur;
        cur=cur->top;
    }
    fprintf(fp1,"%d ",cur->no);  //Appending the pushed element into file
    fclose(fp1);
    prev->top=NULL;  //Deleting the rear element i.e. pop
    free(cur);
    return head;
}
void disp(st head)  //Function displays the elements of a stack
{
    if(head==NULL)
    {
        printf("\nEmpty stack!");
        return;
    }
    st temp=head;
    printf("\n");
    while(temp!=NULL)  
    {
        printf("%d ",temp->no);
        temp=temp->top;
    }
    printf("\n");
}
void random_gen(FILE *fp)
{
    int n,x,y,c;
    printf("\nEnter number: "); //Taking input from user to generate 'n' random number
    scanf("%d",&n);
    printf("\nEnter range x and y: ");  //Taking range from user
    scanf("%d %d",&x,&y);
    for(int i=0;i<n;i++)
    {
        label: c=rand()%y;
        if(c>x && c<y)
            fprintf(fp,"%d ",rand()%c);  //Writing 'n' generated random numbers into "input.txt" 
        else
            goto label;
    }
}
void clear()  //Clearing the data from the file
{
    FILE *fp;
    fp=fopen("push.txt","w");
    fclose(fp);
    fp=fopen("pop.txt","w");
    fclose(fp);
    fp=fopen("log.txt","w");
    fclose(fp);
}
int main()
{
    st head=NULL;
    clear();
    FILE *fp;
    fp=fopen("input.txt","w");
    random_gen(fp);  //Generating random integers
    fclose(fp);
    fp=fopen("input.txt","r");
    while(1)
    {
        int ch;
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=push(head,fp); updated(head);  //Pushes element to rear of linked list
            break;
            case 2: head=pop(head); updated(head);  //Pops the first element from stacks (linked list)
            break;
            case 3: disp(head);  //Display the stack
            break;
            case 4: exit(0);
            default: printf("\nInvalid choice. ");
            break;
        }
    }
    fclose(fp);
    int ch;
    return 0;
}