#include <stdio.h>
#include <stdlib.h>
#define N 10000
typedef struct STACK
{
    int data[N];
    int top;
}st;
void flush()
{
    FILE *fp;
    fp=fopen("push.txt","w");
    fclose(fp);
    fp=fopen("pop.txt","w");
    fclose(fp);
    fp=fopen("log.txt","w");
    fclose(fp);
}
void random_gen(FILE *fp)
{
    int n,x,y,c;
    printf("\nEnter number to be generated:  ");  //Taking input from user to generate 'n' random number
    scanf("%d",&n);
    printf("\nEnter range:  ");  //Taking input for range from user to generate random number
    scanf("%d%d",&x,&y);
    for(int i=0;i<n;i++)
    {
        label: c=rand()%y;
        if(c>x && c<y)
            fprintf(fp,"%d ",c);  //Writing 'n' generated random numbers into "input.txt" 
        else
            goto label;
    }
}
void push(st *s,FILE *fp)
{
    if(s->top==N-1)
    {
        printf("Stack overflow");
        exit(0);
    }
    FILE *fp1,*fp2,*fp3;
    char a[]="push";
    fp1=fopen("push.txt","a");  //Appending "log.txt" with "push" i.e. the operation performed
    fp2=fopen("log.txt","a");
    fp3=fopen("stack.txt","w");
    fscanf(fp,"%d",&s->data[s->top]);  //Reading the element fromm stack
    fprintf(fp1,"%d ",s->data[s->top]);  //Appending the pushed element into "push.txt" 
    s->top++;  //Incrementing stack pointer 
    fprintf(fp2,"%s\n",a);
    for(int i=0;i<s->top;i++)
    {
        fprintf(fp3,"%d ",s->data[i]);  //Writing the updated stack array into "stack.txt" 
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
void pop(st *s,FILE *fp)
{
    if(s->top==0)
    {
        printf("Stack underflow");
        exit(0);
    }
    FILE *fp1,*fp2,*fp3;
    char a[]="pop";
    fp1=fopen("pop.txt","a");
    fp2=fopen("log.txt","a");
    fp3=fopen("stack.txt","w");
    fprintf(fp1,"%d ",s->data[s->top]);  //Appending "pop.txt" with the element i.e. popped from stack
    fprintf(fp2,"%s\n",a);  //Appending "log.txt" with "pop" i.e. the operation performed
    s->top--;  //Decrementing stack pointer 
    for(int i=0;i<s->top;i++)
    {
        fprintf(fp3,"%d ",s->data[i]);  //Writing the updated stack array into "stack.txt" 
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}
void disp(st *s)
{
    for(int i=0;i<s->top;i++)
    {
        printf("%d ",s->data[i]);
    }
}
int main()
{
   flush();
   FILE *fp;
   st *s;
   s->top=0;
   fp=fopen("input.txt","w");  //Opening "input.txt" file in write mode
   random_gen(fp);  //Function call to generate random numbers
   fclose(fp);
   fp=fopen("input.txt","r");  //Opening of "input.txt" file in read mode
   while(1)
   {
        int o;
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n"); 
        printf("\nEtter choice: ");
        scanf("%d",&o);  //Taking integer input from user to perform the operation
        switch(o)
        {
            case 1:push(s,fp);  //Pushes the integer from file pointed by the file pointer 
            break;
            case 2:pop(s,fp);  //Pop removes the top element from the stack and updates stack pointer
            break;
            case 3:disp(s);  //Display of the elements present in stack array
            break;
            case 4:exit(0);  //Function that terminates the program execution
            break;
            default: printf("\nInvalid choice");
            break;
        }
    }
    fclose(fp);
    return 0;
}