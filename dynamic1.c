//Fibonacci Series
#include <stdio.h>
int fibonacci(int n)
{
    int fib[n+2];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
    return fib[n];
}
int main()
{
    int n,c;
    printf("\nEnter number: ");
    scanf("%d",&n);
    c=fibonacci(n);
    printf("\nFibonacci : %d ",c);
    return 0;
}