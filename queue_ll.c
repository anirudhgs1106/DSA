#include <stdio.h>
#include <stdlib.h>
struct QUEUE  //Doubly linked list node for queue
{
    int no;
    struct QUEUE *next;    //Points to the next node of linked list
    struct QUEUE *prev;  //Points to the previous node of linked list
};
typedef struct QUEUE *qe;
qe front=NULL;   
qe rear=NULL; 
void clear()  //Function to clear the data present in the files
{
    FILE *fp;
    fp=fopen("enqueue.txt","w");
    fclose(fp);
    fp=fopen("dequeue.txt","w");
    fclose(fp);
    fp=fopen("log1.txt","w");
    fclose(fp);
} 
void random_gen(FILE *fp)
{
    int n,x,y,c;
    printf("\nEnter number: ");  //Taking input from user to generate "n" numbers
    scanf("%d",&n);
    printf("\nEnter range x and y: ");  //Taking range from user
    scanf("%d%d",&x,&y);
    for(int i=0;i<n;i++)
    {
        label: c=rand()%y;
        if(c<y && c>x)
            fprintf(fp,"%d ",c);  //Writing "n" generated random numbers into files
        else 
            goto label;
    }
}
qe getnode(int c)
{
    qe newn=(qe)malloc(sizeof(struct QUEUE));  //Creating new node for a queue
    newn->no=c;  //Values "c" is stored in newn
    newn->next=NULL;
    newn->prev=NULL;
    return newn;
}
//Function to insert element from rear of the queue i.e. enqueue
void enqueue(FILE *fp)
{
    FILE *fp1;
    fp1=fopen("log1.txt","a");
    char a[]="enqueue";   
    fprintf(fp1,"%s\n",a);  //Appending the "log1.txt" with the opreration performed
    fclose(fp1);
    int c;
    fscanf(fp,"%d",&c);
    fp1=fopen("enqueue.txt","a");
    fprintf(fp1,"%d ",c);  //Appending the "enqueue.txt" with enqueued value
    fclose(fp1);
    qe newn;
    newn=getnode(c);
    if(rear==NULL)
    {
        rear=newn;
        front=rear;
        return ;
    }
    newn->prev=rear;
    rear->next=newn;
    rear=newn;  //Updating rear pointer to the last element of the queue
}
//Function to delete element from front of the queue i.e. dequeue
void dequeue(FILE *fp)
{
    FILE *fp1;
    fp1=fopen("log1.txt","a");
    char a[]="dequeue";
    fprintf(fp1,"%s\n",a);  //Appending the "log1.txt" with the opreration performed 
    fclose(fp1);
    if(front==NULL)
    {
        printf("\nQueue Empty.\n");
        return ;
    }
    fp1=fopen("dequeue.txt","a");
    fprintf(fp1,"%d ",front->no);  //Appending the "dequeue.txt" with dequeued value
    fclose(fp1);
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
        return ;
    }
    front=front->next;  //Updating front pointer to the next elementn of the queue
}
//Function to display the queue 
void disp()
{
    if(rear==NULL)
    {
        printf("\nEmpty Queue.\n");
        return;
    }
    qe temp=front;
    printf("\n");
    while(temp!=rear)
    {
        printf("%d ",temp->no);
        temp=temp->next;
    }
    printf("%d ",temp->no);
    printf("\n");
}
//Function to update the "queue.txt" file after enqueue and dequeue operations
void update()
{
    FILE *fp2;
    fp2=fopen("queue.txt","w");
    qe temp=front;
    if(front!=NULL)
    {
        while(temp!=rear)
        {
            fprintf(fp2,"%d ",temp->no);
            temp=temp->next;
        }
        fprintf(fp2,"%d ",temp->no);
    }
    fclose(fp2);
}
int main()
{
    clear();
    FILE *fp; 
    fp=fopen("input.txt","w");
    random_gen(fp);
    fclose(fp);
    fp=fopen("input.txt","r");
    while(1)
    {
        int o;
        printf("\n1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n");
        printf("\nEnter choice:  ");
        scanf("%d",&o);
        switch(o)
        {
            case 1: enqueue(fp); update(); //Function call for enqueue at front and upadate updated queue into file 
            break;
            case 2: dequeue(fp); update();  //Function call for dequeue at front and upadate updated queue into file
            break;
            case 3: disp();
            break;
            case 4: exit(0);  //Exit to terminate from infinite loop
            default: printf("\nInvalid choice\n");
            break;
        }
    }
    fclose(fp);
}