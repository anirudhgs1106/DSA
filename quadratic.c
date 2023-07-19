//Open Addressing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define table_size 10
struct TABLE
{
    int *key,*value;
    bool *occupied;
};
typedef struct TABLE *table;
table create_table()
{
    table newn=(table)malloc(sizeof(struct TABLE));
    newn->key=(int*)calloc(table_size,sizeof(int));
    newn->value=(int*)calloc(table_size,sizeof(int));
    newn->occupied=(bool*)calloc(table_size,sizeof(bool));
    return newn;
}
int hashkey(int key)
{
    return key%table_size;
}
int quadratic(int key,int i)
{
    return (hashkey(key)+i*i)%table_size;
}
void insert(table t,int key,int value)
{
    int index=hashkey(key);
    int i=0;
    while(t->occupied[index])
    {
        i++;
        index=quadratic(key,i);
    }
    t->key[index]=key;
    t->value[index]=value;
    t->occupied[index]=true;
}
int search(table t,int key)
{
    int index=hashkey(key);
    int i=0;
    while(t->occupied[index])
    {
        if(t->key[index]==key)
            return t->value[index];
        i++;
        index=quadratic(key,i);
    }
    return -1;
}
int main()
{
    table t=create_table();
    insert(t,5,100);
    insert(t,15,500);
    int value1=search(t,5);
    int value2=search(t,35);
    printf("\nValue of key 5: %d",value1);
    printf("\nValue of key 35: %d",value2);
    return -1;
}
/*
Value of key 5: 100
Value of key 35: -1%  
*/