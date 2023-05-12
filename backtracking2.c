//Rat in a Maze
#include <stdio.h>
#include <stdbool.h>
void  disp(int arr1[4][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
}
bool safe(int arr[4][4],int m,int n)
{
    if(m>=0 && n>=0 && m<4 && n<4 && arr[m][n]==1)
        return true;
    return false;
}
bool solvemaze(int arr[4][4],int m,int n,int arr1[4][4])
{
    if(m==3 && n==3 && arr[m][n]==1)
    {
        arr1[m][n]=1;
        return true;
    }
    if(safe(arr,m,n)==true)
    {
        if(arr1[m][n]==1)
            return false;
        arr1[m][n]=1;
        if(solvemaze(arr,m+1,n,arr1)==true) 
            return true;
        if(solvemaze(arr,m,n+1,arr1)==true) 
            return true;
        arr1[m][n]=0;
        return false;
    }
    return false;
}
void solve(int arr[4][4])
{
    int arr1[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    if(solvemaze(arr,0,0,arr1)==false)
    {
        printf("\nSolution doesn't exist");
        return ;
    }
    disp(arr1);
}
int main()
{
    int arr[4][4]={{1,0,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
    solve(arr);
    return 0;
}