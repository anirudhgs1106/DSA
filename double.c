//Cuckoo Hashing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 10
#define max 5
struct hashtable
{
    int* table1;
    int* table2;
    bool* occupied1;
    bool* occupied2;
};
struct hashtable hash;
void initialize() 
{
    hash.table1 = (int*)calloc(size, sizeof(int));
    hash.table2 = (int*)calloc(size, sizeof(int));
    hash.occupied1 = (bool*)calloc(size, sizeof(bool));
    hash.occupied2 = (bool*)calloc(size, sizeof(bool));
}
int primhash(int key) 
{
    return key % size;
}
int seconhash(int key) 
{
    return (key / size) % size;
}
void insert(int key) 
{
    int hash1 = primhash(key);
    int hash2 = seconhash(key);

    if (!hash.occupied1[hash1]) 
    {
        hash.table1[hash1] = key;
        hash.occupied1[hash1] = true;
        printf("Inserted key %d into hash table 1.\n", key);
    }
    else if (!hash.occupied2[hash2])
    {
        hash.table2[hash2] = key;
        hash.occupied2[hash2] = true;
        printf("Inserted key %d into hash table 2.\n", key);
    } 
    else 
    {
        for (int i = 0; i < max; i++) 
        {
            int temp = hash.table1[hash1];
            hash.table1[hash1] = key;
            key = hash.table2[hash2];
            hash.table2[hash2] = temp;
            hash1 = primhash(key);
            hash2 = seconhash(key);
            if (!hash.occupied1[hash1]) 
            {
                hash.table1[hash1] = key;
                hash.occupied1[hash1] = true;
                printf("Inserted key %d into hash table 1 after kicking.\n", key);
                return;
            }
            if (!hash.occupied2[hash2]) 
            {
                hash.table2[hash2] = key;
                hash.occupied2[hash2] = true;
                printf("Inserted key %d into hash table 2 after kicking.\n", key);
                return;
            }
        }
        printf("Failed to insert key %d into the cuckoo hash table after maximum kicks.\n", key);
    }
}
bool search(int key) 
{
    int hash1 = primhash(key);
    int hash2 = seconhash(key);
    if (hash.table1[hash1] == key && hash.occupied1[hash1])
        return true;
    if (hash.table2[hash2] == key && hash.occupied2[hash2])
        return true;
    return false;
}
int main()
{
    initialize();
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    insert(10);
    insert(20);
    insert(30);

    bool keyFound1 = search(25);
    bool keyFound2 = search(40);

    printf("Key 25 found in the cuckoo hash table: %s\n", keyFound1 ? "true" : "false"); // Output: true
    printf("Key 40 found in the cuckoo hash table: %s\n", keyFound2 ? "true" : "false"); // Output: false

    return 0;
}

/*
Inserted key 5 into hash table 1. 
Inserted key 15 into hash table 2. 
Inserted key 25 into hash table 2. 
Inserted key 35 into hash table 2. 
Inserted key 10 into hash table 1. 
Inserted key 5 into hash table 2 after kicking. 
Failed to insert key 30 into the cuckoo hash table after maximum kicks. 
Key 25 found in the cuckoo hash table: true 
Key 40 found in the cuckoo hash table: false 
*/