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
        if(c>x && y>c)
            fprintf(fp,"%d ",c);  //Writing "n" generated random numbers into files 
        else goto label;
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
//Function to insert element into rear of the queue
void enqueue_rear(FILE *fp)  
{
    FILE *fp1;
    fp1=fopen("log1.txt","a");
    char a[]="enqueue rear";
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
    rear=newn;
    return;
}
//Function to insert element into front of the queue
void enqueue_front(FILE *fp)  
{
    FILE *fp1;
    fp1=fopen("log1.txt","a");
    char a[]="enqueue front";
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
    front->prev=newn;
    newn->next=front;
    front=newn;
    return;
} 
//Function to delete element from rear of the queue
void dequeue_rear()  
{
    FILE *fp1;
    fp1=fopen("log1.txt","a");
    char a[]="dequeue rear";
    fprintf(fp1,"%s\n",a);
    fclose(fp1);
    fp1=fopen("dequeue.txt","a");
    if(front==NULL)
    {
        printf("\nEmpty Queue");
        return;
    }
    if(front==rear)
    {
        fprintf(fp1,"%d ",front->no);
        fclose(fp1);
        front=NULL;
        rear=NULL;
        return;
    }
    fprintf(fp1,"%d ",rear->no);
    fclose(fp1);
    rear=rear->prev;
    rear->next=NULL;
    return;
}
 //Function to delete element from front of the queue
void dequeue_front() 
{
    FILE *fp1;
    fp1=fopen("log1.txt","a");
    char a[]="dequeue front";
    fprintf(fp1,"%s\n",a);
    fclose(fp1);
    fp1=fopen("dequeue.txt","a");
    if(front==NULL)
    {
        printf("\nEmpty Queue");
        return;
    }
    if(front==rear)
    {
        fprintf(fp1,"%d ",front->no);
        front=NULL;
        rear=NULL;
        fclose(fp1);
        return;
    }
    fprintf(fp1,"%d ",front->no);
    fclose(fp1);
    front->next->prev=NULL;
    front=front->next;
    return;
}
//Function to display the queue 
void disp()  
{
    if(front==NULL)
    {
        printf("\nEmpty Queue!\n");
        return;
    }
    if(front!=NULL)
    {
        qe temp=front;
        while(temp!=rear)
        {
            printf("%d ",temp->no);
            temp=temp->next;
        }
        printf("%d ",temp->no);
    }
}
//Function to update the "queue.txt" file after enqueue and dequeue operations
void update()
{
    FILE *fp2;
    fp2=fopen("queue.txt","w");
    if(front!=NULL)
    {
        qe temp=front;
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
    random_gen(fp);  //Function call to generate random numbers
    fclose(fp);
    fp=fopen("input.txt","r");
    while(1)
    {
        int ch;
        printf("\n1.EnQueue Front\n2.EnQueue Rear\n3.DeQueue Front\n4.DeQueue Rear\n5.Display\n6.Exit\n");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue_front(fp); update();  //Function call for enqueue at front 
            break;
            case 2: enqueue_rear(fp); update();  //Function call for enqueue at rear
            break;
            case 3: dequeue_front(); update();  //Function call for dequeue from front 
            break;
            case 4: dequeue_rear(); update();  //Function call for dequeue from rear
            break;
            case 5: disp(); 
            break;
            case 6: exit(0);  //Exit to terminate from infinite loop
            default: printf("\nInvalid choice.");
            break;
        }
    }
    fclose(fp);
    return 0;
}