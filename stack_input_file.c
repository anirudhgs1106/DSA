/*CONTENT IN FILE 
5P 1p  (P - Push and p - Pop)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000
int p=0;  //The variable p is used to track the top element of stack
void random_gen(FILE *fp)
{
    int n,x,y,c;
    printf("\nEnter total number to be generated: ");  //Taking input from user to generate 'n' random number
    scanf("%d",&n);
    printf("\nEnter ranges x,y : ");  //Taking input for range from user to generate random number
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
void disp(int stack[N])  //Displaying the elements in stack
{
    for(int i=0;i<p;i++)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
void push(FILE *fp,int stack[N])
{
    FILE *fp1,*fp3,*fp4;
    fp3=fopen("log.txt","a"); 
    fp4=fopen("stack.txt","w"); 
    char a[]="push";
    fprintf(fp3,"%s\n",a);  //Appending "log.txt" with "push" i.e. the operation performed
    fp1=fopen("push.txt","a");  
    fscanf(fp,"%d",&stack[p]);  //Reading the element fromm stack
    fprintf(fp1,"%d ",stack[p]);  //Appending "push.txt" with the element i.e. pushed in stack
    p++;  //Incrementing stack pointer 
    fclose(fp1); 
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
    fp4=fopen("stack.txt","w");
    fp3=fopen("log.txt","a");
    char b[]="pop";
    fprintf(fp3,"%s\n",b);  //Appending "log.txt" with "pop" i.e. the operation performed
    fp2=fopen("pop.txt","a");
    p--;  //Decrementing stack pointer 
    fprintf(fp2,"%d ",stack[p]);  //Appending "pop.txt" with the element i.e. popped
    fclose(fp2);
    fclose(fp3);
    for(int i=0;i<p;i++)
    {
        fprintf(fp4,"%d ",stack[i]);  //Writing the updated stack array into "stack.txt" 
    }
    fclose(fp4);
}
int main()
{
    FILE *fp,*fp1;
    int stack[N];
    char m[N],n[N];
    fp=fopen("input.txt","w");
    random_gen(fp);
    fclose(fp);
    fp=fopen("input.txt","r");
    fp1=fopen("operation.txt","r");
    int t;
    while(!feof(fp1))
    {
        fscanf(fp1,"%d\n",&t);
        printf("%d ",t);  //Reading number of times operation to perform
       fscanf(fp1,"%c\n",m);
        puts(m);
        if(strcmp(m,"P")==0)  //compare if "P" then push operation is performed
        {
            for(int i=0;i<t;i++)
                push(fp,stack);
            disp(stack);
        }
        else if(strcmp(m,"p")==0)  //compare if "p" then pop operation is performed
        {
            for(int i=0;i<t;i++)
                pop(fp,stack);
            disp(stack);
        }
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}