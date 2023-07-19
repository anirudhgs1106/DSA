//Threaded Binary Tree 
#include <stdio.h>
#include <stdlib.h>
struct TREE 
{
    int data,thread; 
    struct TREE *left,*right;
};
typedef struct TREE *tree;
tree getnode(int data)
{
    tree newn=(tree)malloc(sizeof(struct TREE));
    newn->left=NULL;
    newn->right=NULL;
    newn->data=data;
    newn->thread=0;
    return newn;
}
void inorder(tree root)
{
    tree temp=root;
    while(temp!=NULL)
    {
        while(temp->left!=NULL)
            temp=temp->left;
        printf("%d ",temp->data);
        if(temp->thread)
            temp=temp->right;
        else
        {
            temp=temp->right;
            while(temp!=NULL && !temp->thread)
                temp=temp->left;
        }
    }
}
tree threaded_tree(int arr[],int size)
{
    tree newn=getnode(arr[0]);
    tree prev=newn;
    for(int i=1;i<size;i++)
    {
        tree cur=getnode(arr[i]);
        if(prev->right==NULL)
        {
            prev->right=cur;
            prev->thread=1;
        }
        else
        {
            while(prev->thread!=1)
                prev=prev->right;
            prev->right=cur;
            prev->thread=0;
        }
        cur->right=prev;
        cur->thread=1;
        prev=cur;
    }
    return newn;

}
int main()
{
    int arr[]={4,2,6,1,3,5,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    tree root=NULL;
    root=threaded_tree(arr,size);
    printf("\nInorder Traversal of Threaded Binary Tree:  ");
    inorder(root);
    return 0;
}
/*
Inorder Traversal of Threaded Binary Tree:  4 2
*/