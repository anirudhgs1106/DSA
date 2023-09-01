//N Queen's Problem
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define N 5
bool safe(int i,int j,int sc[N][N],int bs[N][N],bool rl[],bool scl[],bool bscl[])
{
    if(scl[sc[i][j]] || bscl[bs[i][j]] || rl[i])
        return false;
    return true;
}
bool solve1(int b[N][N],int c, int sc[N][N],int bs[N][N],bool rl[],bool scl[],bool bscl[])
{
    if(c>=N)
        return true;
    for(int i=0;i<N;i++)
    {
        if(safe(i,c,sc,bs,rl,scl,bscl))
        {
            b[i][c]=1;
            rl[i]=true;
            scl[sc[i][c]]=true;
            bscl[bs[i][c]]=true;
            if(solve1(b,c+1,sc,bs,rl,scl,bscl))
                return true;
            b[i][c]=0;
            rl[i]=false;
            scl[sc[i][c]]=false;
            bscl[bs[i][c]]=false;
        }
    }
    return false;
}
bool solve()
{
    int b[N][N];
    memset(b,0,sizeof(b));
    int sc[N][N];
    int bs[N][N];
    bool rl[N]={false};
    bool scl[2*N-1]={false};
    bool bscl[2*N-1]={false};
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            sc[i][j]=i+j;
            bs[i][j]=i-j+7;
        }
    }
    if(solve1(b,0,sc,bs,rl,scl,bscl)==false)
    {
        printf("\nSolution doesn't exist");
        return false;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return true;
}
int main()
{
    solve();
    return 0;
}