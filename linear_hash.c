//Caching
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define cache_size 10
struct CACHE
{
    int key,value;
    bool empty;
};
struct CACHE cache[cache_size];
void initial()
{
    for(int i=0;i<cache_size;i++)
        cache[i].empty=true;
}
int gethash(int key)
{
    return key%cache_size;
}
void insert(int key,int value)
{
    int hash=gethash(key);
    while(!cache[hash].empty)
        hash=(hash+1)%cache_size;
    cache[hash].key=key;
    cache[hash].value=value;
    cache[hash].empty=false;
}
int getvalue(int key)
{
    int hash=gethash(key);
    while(!cache[hash].empty)
    {
        if(cache[hash].key==key)
            return cache[hash].value;

        hash=(hash+1)%cache_size;
    }
    return -1;
}
int main()
{
    initial();
    insert(1,100);
    insert(4,500);
    int value1=getvalue(1);
    int value2=getvalue(3);
    printf("Value of Key 1: %d\n",value1);
    printf("Value of Key 3: %d\n",value2);
    return 0;
}
/*
Value of Key 1: 100
Value of Key 3: -1
*/