#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct NODE  //struct NODE with an integer variable a and a pointer to the next NODE
{
    int a;  //Variable 'a' is an integer data type which can hold any integer value
    struct NODE *next;  //'next' is a pointer to the next node in a linked list
};
typedef struct NODE *node;  //Creating a new type 'node' which is pointer to 'struct NODE'
void number(FILE *fp)  //Function takes file pointer 'fp' as input
{
    int n;
    printf("\nEnter total random number to be generated : ");  //Taking input from user to generate 'n' number of random elements
    scanf("%d",&n);
    for(int i=0;i<n;i++)  //Loop that iterates 'n' times. It is used to generate 'n' random integers
    {
        fprintf(fp,"%d ",rand()%100);  ////Generating random integers from 0 to 99 and writing in file
    }
}
node insert(int c,node head)
{
    node newn=(node)malloc(sizeof(struct NODE));  //Allocating memory dynamically using 'malloc()'
    newn->a=c;  //Assigning the value of 'c' to integer variable 'a' of newly created node newn 
    newn->next=NULL;  //Initializing the pointer variable 'next' of newly created node 'newn' to 'NULL'
    if(head==NULL)  //Checking if the linked list is empty or not
    {
        return newn;  //'newn' is the first node of linked list if linked list is empty
    }
    else 
    {
        node temp=head;  //Created new pointer variable 'temp' and initializing it witt the address of first node of linked list
        while(temp->next!=NULL)  //If linked list is not empty, 'while' loop traverses the linked list till end
        {
            temp=temp->next;
        }
        temp->next=newn;  //and adds the newly created node 'newn' at the end of the linked list
        return head;
    }
}
node linked(FILE *fp,node head)  //
{
    int m,c;
    printf("\nEnter number to be sorted: ");
    scanf("%d",&m);
    node temp;
    for(int i=0;i<m;i++)
    {
        fscanf(fp,"%d",&c);
        head=insert(c,head);
    }
    return head;
}
void sort(node head)
{
    node cur=head,temp=head;
    while(cur->next!=NULL)
    {
        while(temp->next!=NULL)
        {
            if(temp->a>temp->next->a)
            {
                int temp1;
                temp1=temp->a;
                temp->a=temp->next->a;
                temp->next->a=temp1;
            }
            temp=temp->next;
        }
        cur=cur->next;
        temp=head;
    }
}
/*void disp(node head)
{
    node cur=head;
    if(head==NULL)
    {
        printf("\nNo elements in linked list");
        return;
    }
    printf("\ndisplay ");
    while(cur!=NULL)
    {
        printf("%d ",cur->a);
        cur=cur->next;
    }
}*/
int main()
{
    FILE *fp;  //Declaration of file pointer named fp
    node head=NULL;  //Initializing a pointer varibale 'head' to 'NULL' indicating that the linked list is currently empty
    time_t t1,t2;  //Declaring two variable of tyoe 'time_t' named 't1' and 't2'
    fp=fopen("trial.txt","w");  //Opening of file in write mode
    if(fp==NULL)
    {
        printf("\nFile not created");
        exit(0);
    }
    number(fp);  //Calling the function and passing the file pointer 'fp' as argument
    fclose(fp);  //Closing of file 
    fp=fopen("trial.txt","r");  //Opening of file in read mode
    if(fp==NULL)
    {
        printf("\nFile not opened");
        exit(0);
    }
    head=linked(fp,head);  //Calling the function and passing the file pointer 'fp' and pointer variable 'head' as arguments
                           //The function returns the updated pointer variable 'head', which is assigned to 'head' in the main function
    fclose(fp);  //Closing of file 
    //disp(head);
    t1=time(NULL);  //Assigning the current time in sec to variable 't1'
    sort(head);  //Calling the function and passing the pointer variable 'head'
    t2=time(NULL);  //Assigning the current time in sec to variable 't2'
    //disp(head);
    printf("\nTime taken:  %d",t2-t1);  //Display of time taken to sort the linked list in sec
    return 0;
}