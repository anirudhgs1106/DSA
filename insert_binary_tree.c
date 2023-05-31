//Binary tree
#include <stdio.h>
#include <stdlib.h>
struct TREE
{
    int data;
    struct TREE *left;  //Pointer to the left child nodes of binary tree
    struct TREE *right;  //Pointer to the right child nodes of binary tree
};
typedef struct TREE *tree;
//Function to create a new node for a binary tree with the given data and return it 
tree getnode(int data)  
{
    tree newn=(tree)malloc(sizeof(struct TREE));
    newn->left=NULL;
    newn->right=NULL;
    newn->data=data;
    return newn;
}
tree insert(tree root,int data)
{
    if(root==NULL)  //Base condition for recursion call
    {
        root=getnode(data);  //new node is crreated with given data and returned as new root
        return root;
    }
    if(data < root->data)
        root->left=insert(root->left,data);  //Recursively inserting the new node with the given data into the left sub-tree if smaller than root->data 
    if(data > root->data)
        root->right=insert(root->right,data);  //Recursively inserting the new node with the given data into the right sub-tree if greater than root->data 
    return root;
}
//Display of binary tree in left node,root node ,right node order
inorder(tree root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
//Display of binary tree in root node,left node ,right node order
void preorder(tree root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
//Display of binary tree in left node,right node,root node order
postorder(tree root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    tree root=NULL;
    while(1)
    {
        int ch,data;
        printf("\n1.Insert\n2.In-Order\n3.Pre-order\n4.Post-Order\n5.Exit\n");
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter data: ");
                    scanf("%d",&data);
                    root=insert(root,data);  //Function call to insert the data into tree
                    break;
            case 2: printf("\nIn-Order\n");
                    inorder(root);  //Function call to display tree in In-Order
                    break;
            case 3: printf("\nPre-Order\n");
                    preorder(root);  //Function call to display tree in Pre-Order
                    break;
            case 4: printf("\nPost-Order\n");
                    postorder(root);  //Function call to display tree in Post-Order
                    break;
            case 5: exit(0);
            default: printf("\nInvalid choice!\n");
            break;
        }
    }
    return 0;
}
/*
    else
    {
        if(data < root->data)
        {
            root->left=insert(root->left,data);
            return root;
        }
        else if(data > root->data)
        {
            root->right=insert(root->right,data);
            return root; 
        }
    }*/