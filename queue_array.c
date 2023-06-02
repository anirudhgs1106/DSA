#include <stdio.h>
#include <stdlib.h>
#define N 10000
int front=-1,rear=-1;
void clear()
{
    FILE *fp=fopen("enqueue.txt","w");
    fclose(fp);
    fp=fopen("dequeue.txt","w");
    fclose(fp);
    fp=fopen("log1.txt","w");
    fclose(fp);
}
void random_gen(FILE *fp)
{
    int n,c,x,y;
    printf("\nEnter number of random numbers to be generated:  ");  //Taking input from user to generate random numbers
    scanf("%d",&n);
    printf("\nEnter range x and y: ");  //Taking range as input
    scanf("%d%d",&x,&y);
    for (int i=0;i<n;i++)
    {
        label: c=rand()%y;
        if(c>x && c<y)
            fprintf(fp,"%d ",c);  //writing "n" random numbers into file
        else 
            goto label;
    }
}
void enqueue(int arr[N],FILE *fp)
{
    if(rear==N-1)
    {
        printf("\nQueue overflow");  
        return;
    }
    int c;
    fscanf(fp,"%d",&c);
    if(front==-1 && rear==-1)
        front++;
    rear++;
    arr[rear]=c;
    FILE *fp1;
    fp1=fopen("enqueue.txt","a");
    fprintf(fp1,"%d ",c);  //Appending file with enqueued element
    fclose(fp1);
    fp1=fopen("log1.txt","a");
    fprintf(fp1,"%s\n","enqueue");  //Appending file with "enqueue" i.e. the operation performed
    fclose(fp1);
    fp1=fopen("queue.txt","w");
    for(int i=front;i<=rear;i++)
        fprintf(fp1,"%d ",arr[i]);  //Updated "queue.file" with updated queue
    fclose(fp1);
}
void dequeue(int arr[N])
{
    if(front>rear || front==-1)
    {
        printf("\nQueue underflow");
        return;
    }
    FILE *fp1;
    fp1=fopen("dequeue.txt","a");
    fprintf(fp1,"%d ",arr[front]);  //Appending file with dequeued element
    fclose(fp1);
    front++;
    fp1=fopen("log1.txt","a");
    fprintf(fp1,"%s\n","dequeue");  //Appending file with "dequeue" i.e. the operation performed
    fclose(fp1);
    fp1=fopen("queue.txt","w");
    for(int i=front;i<=rear;i++)
        fprintf(fp1,"%d ",arr[i]);  //Updated "queue.file" with updated queue
    fclose(fp1);

}
//Display of Queue 
void disp(int arr[N])  
{
    if(front==-1 || rear==-1)
    {
        printf("\nQueue Empty");
        return ;
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    clear();
    int arr[N];
    FILE *fp;
    fp=fopen("input.txt","w");
    random_gen(fp);
    fclose(fp);
    fp=fopen("input.txt","r");
    while(1)
    {
        int ch;
        printf("\n1.EnQueue\n2.DeQueue\n3.Display\n4.Exit\n");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue(arr,fp);  //Function call for enqueue operation
            break;
            case 2: dequeue(arr);  //Function call for dequeue operation
            break;
            case 3: disp(arr);
            break;
            case 4: exit(0);  
        }
    }
    return 0;
}