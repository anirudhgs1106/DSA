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
node linked(FILE *fp,node head)  //Function to read integers from file pointer 'fp' and insert them into linked list pointed by 'head'
{
    int m,c;
    printf("\nEnter number to be sorted: ");  //Taking input from user to enter number of integers to be sorted
    scanf("%d",&m);
    node temp;
    for(int i=0;i<m;i++)
    {
        fscanf(fp,"%d",&c);  //Reading an integer from file pointed by 'fp' and storing it in the variable 'c'
        head=insert(c,head);  //Calling function and passing two arguments : integer value 'c' and pointer variable 'head'
                              //Insert creates newnode with integer value 'c' and adds it to the end of linked list pointed by 'head'
    }
    return head;  //returning the updated pointer to the head of linked list
}
//The function sorts linked list in ascending orders using the bubble sort
void sort(node head)
{
    node cur=head,temp=head;
    while(cur->next!=NULL)  //This loop iterates through linked list until the last node is reached
    {
        while(temp->next!=NULL)  //This loop iterates through linked list until the second last node is reached
        {
            if(temp->a>temp->next->a)  //Checks if the current node value is greater than the next node's value
            {
                int temp1=temp->a;  //This variable is used to temporarily store values of an element during swapping process
                temp->a=temp->next->a;  //Assigning the value of the 'a' variable of next node to the 'a' variable of current node
                temp->next->a=temp1;  //Assigning the value of 'temp1' to the value of 'a' variable of next node
            }
            temp=temp->next;  //Updating pointer variable 'temp' to point to next node in the linked list 
        }
        cur=cur->next;  //Updating pointer variable 'cur' to point to next node in the linked list 
        temp=head;  //Assigning the value of 'head' to the pointer variable 'temp'
                    //Assigned to traverse the linked list from first node    
    }
}
void write(FILE *fp,node head)
{
    node temp=head;  //Initializing new pointer "variable" with the address of first node
    while(temp!=NULL)
    {
        fprintf(fp,"%d ",temp->a);  //Traversiing the linked list and writing integers to "output.txt" file
        temp=temp->next;
    }
}
int main()
{
    FILE *fp;  //Declaration of file pointer named fp
    node head=NULL;  //Initializing a pointer varibale 'head' to 'NULL' indicating that the linked list is currently empty
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
    sort(head);  //Calling the function and passing the pointer variable 'head'
    fp=fopen("output.txt","w");  //Opening of file in write mode
    if(fp==NULL)
    {
        printf("\nFile not created");
        exit(0);
    }
    write(fp,head);  //
    fclose(fp);
    return 0;
}