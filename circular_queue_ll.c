#include <stdio.h>
#include <stdlib.h>
struct QUEUE  //Doubly linked list node for queue
{
    int no;
    struct QUEUE *next;  //Points to the next node of linked list
    struct QUEUE *prev;  //Points to the previous node of linked list
};
typedef struct QUEUE *qe;
qe front=NULL;
qe rear=NULL;
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
//Function to clear the data present in the files
void clear()  
{
    FILE *fp;
    fp=fopen("enqueue.txt","w");
    fclose(fp);
    fp=fopen("dequeue.txt","w");
    fclose(fp);
    fp=fopen("log1.txt","w");
    fclose(fp);
}
qe getnode(int c)
{
    qe newn=(qe)malloc(sizeof(struct QUEUE));  //Creating new node for a queue
    newn->no=c;  //Values "c" is stored in newn
    newn->next=newn;  
    newn->prev=newn;
    return newn;
}
//Function to insert element into the queue
void enqueue(FILE *fp)
{
    FILE *fp1;
    fp1=fopen("log1.txt","a");
    char a[]="enqueue";
    fprintf(fp1,"%s\n",a);
    fclose(fp1);
    int c;
    fscanf(fp,"%d",&c);
    fp1=fopen("enqueue.txt","a");
    fprintf(fp1,"%d ",c);
    fclose(fp1);
    qe newn=getnode(c);
    if(front==NULL)
    {
        front=newn;
        rear=front;
        return;
    }
    rear->next=newn;
    newn->prev=rear;
    newn->next=front;
    front->prev=newn;
    rear=newn;
    return ;
}
//Function to delete element from the queue
void dequeue()
{
    FILE *fp1;
    fp1=fopen("log1.txt","a");
    char a[]="dequeue";
    fprintf(fp1,"%s\n",a);
    fclose(fp1);
    fp1=fopen("dequeue.txt","a");
    if(front==NULL)
    {
        printf("\nEmpty Queue\n");
        return;
    }
    if(front==rear)
    {
        fprintf(fp1,"%d ",front->no);
        front=NULL;
        rear=NULL;
        return ;
    }
    fprintf(fp1,"%d ",front->no);
    fclose(fp1);
    rear->next=front->next;
    front->next->prev=rear;
    front=front->next;
    return ;
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
//Function to display the elements in Queue
void disp()
{
    if(front==NULL)
    {
        printf("\nQueue Empty!\n");
        return;
    }
    qe temp=front;
    while(temp!=rear)
    {
        printf("%d ",temp->no);
        temp=temp->next;
    }
    printf("%d\n",temp->no);
}
int main()
{
    clear();
    FILE *fp;
    fp=fopen("input.txt","w");
    random_gen(fp);  //Function call to generate random numbers
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
            case 1: enqueue(fp); update();  //Function call for enqueue and update "queue.txt" after operations
            break;
            case 2: dequeue(); update();  //Function call for dequeue and update "queue.txt" after operations
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
