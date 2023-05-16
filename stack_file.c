#include <stdio.h>
#include <stdlib.h>
#define N 10000
int p=0;  //The variable p is used to track the top element of stack
void random_gen(FILE *fp)
{
    int n,x,y;
    printf("\nEnter total number to be generated: ");  //Taking input from user to generate 'n' random number
    scanf("%d",&n);
    printf("\nEnter ranges x,y : ");  //Taking input for range from user to generate random number
    scanf("%d%d",&x,&y);
    for(int i=0;i<n;i++)
    {
        fprintf(fp,"%d ",rand()%(y-x));  //Writing 'n' generated random numbers into "input.txt" 
    }
}
void push(FILE *fp,int stack[N])
{
    FILE *fp1,*fp3,*fp4;
    fp3=fopen("log.txt","a");  //Opening "log.txt" file in append mode to update operation
    fp4=fopen("stack.txt","w");  //Opening "stack.txt" file in write mode
    char a[]="push";
    fprintf(fp3,"%s\n",a);  //Appending "log.txt" with "push" i.e. the operation performed
    fp1=fopen("push.txt","a");  //Appending "push.txt" with the element i.e. pushed in stack
    fscanf(fp,"%d",&stack[p]);  //Reading the element fromm stack
    fprintf(fp1,"%d ",stack[p]);  //Writing the pushed element into "push.txt" 
    p++;  //Incrementing stack pointer 
    fclose(fp1);  //Closing of "push.txt" file
    fclose(fp3);
    for(int i=0;i<p;i++)
    {
        fprintf(fp4,"%d ",stack[i]);  //Writing the updated stack array into "stack.txt" 
    }
    fclose(fp4);
}
void pop(FILE *fp,int stack[N])
{
    FILE *fp2,*fp3,*fp4;
    fp4=fopen("stack.txt","w");  //Opening "stack.txt" file in write mode
    fp3=fopen("log.txt","a");  //Opening "log.txt" file in append mode to update operation
    char b[]="pop";
    fprintf(fp3,"%s\n",b);  //Appending "log.txt" with "pop" i.e. the operation performed
    fp2=fopen("pop.txt","a");  //Appending "push.txt" with the element i.e. popped fromvstack
    p--;  //Decrementing stack pointer 
    fprintf(fp2,"%d ",stack[p]);  //Writing the popped element into "pop.txt" file
    fclose(fp2);  //Closing of "pop.txt" file
    fclose(fp3);
    for(int i=0;i<p;i++)
    {
        fprintf(fp4,"%d ",stack[i]);  //Writing the updated stack array into "stack.txt" 
    }
    fclose(fp4);
}
void disp(int stack[N])
{
    for(int i=0;i<p;i++)
    {
        printf("%d ",stack[i]);  //Display of elements present in the stack array
    }
    printf("\n");
}
int main()
{
    FILE *fp;
    int o; 
    int stack[N];
    fp=fopen("input.txt","w");  //Opening "input.txt" file in write mode
    random_gen(fp);  //Function call to generate random numbers
    fclose(fp);  //Closing of file 
    fp=fopen("input.txt","r");  //Opening of "input.txt" file in read mode
    while(1)  //Runing loop infinite times
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        scanf("%d",&o);  //Taking integer input from user to perform the operation
        switch(o)
        {
            case 1:push(fp,stack);  //Pushes the integer from file pointed by the file pointer 
            break;
            case 2:pop(fp,stack);  //Pop removes the top element from the stack and updates stack pointer
            break;
            case 3:disp(stack);  //Display of the elements present in stack array
            break;
            case 4:exit(0);  //Function that terminates the program execution
            break;
            default: printf("\nInvalid choice");
            break;
        }
    }
    fclose(fp);  //Closing of file
    return 0;
}