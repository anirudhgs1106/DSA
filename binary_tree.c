#include <stdio.h>
#include <stdlib.h>
struct TREE
{
    int data;
    struct TREE *left;
    struct TREE *right;
};
typedef struct TREE *tree;
//Function to create a new node for a binary tree with the given data and return it 
tree getnode(int data)
{
    tree newn=(tree)malloc(sizeof(struct TREE));
    newn->data=data;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
}
//Function to calculate the height binary tree
int getheight(tree root)
{
    if(root==NULL)
        return -1;
    else
    {
        int left=getheight(root->left);
        int right=getheight(root->right);
        if(left>right)
            return left+1;
        else
            return right+1;
    }
}
//Function to perform left rotation on a binary tree
tree left_rotate(tree root)
{
    tree newn=root->right;
    root->right=newn->left;
    newn->left=root;
    return newn;  //Returning new root of subtree after performing a left rotation
}
//Function to perform right rotation on a binary tree
tree right_rotate(tree root)
{
    tree newn=root->left;
    root->left=newn->right;
    newn->right=root;
    return newn;  //Returning new root of subtree after performing a right rotation
}
tree balance(tree root)
{
    int balance=getheight(root->left)-getheight(root->right);
    if (balance > 1 && getheight(root->left->left) >= getheight(root->left->right))
        return right_rotate(root);  //If true, left tree has more elements and right rotation is performed to balance
    if (balance < -1 && getheight(root->right->right) >= getheight(root->right->left))
        return left_rotate(root);  //If true, right tree has more elements and left rotation is performed to balance
    if (balance > 1 && getheight(root->left->left) < getheight(root->left->right))
    {
        root->left=left_rotate(root->left);  //If true, left subtree has more elements on right side therefore
        return right_rotate(root);           //left rotation and right rotation are performed for balancing
    }
    if (balance < -1 && getheight(root->right->right) < getheight(root->right->left))
    {
        root->right=right_rotate(root->right);  //If true, right subtree has more elements on left side therefore
        return left_rotate(root);               //right rotation and left rotation are performed for balancing
    }
    return root;
}
tree insert(tree root,int data)
{
    if(root==NULL)  //Base condition for recursion call
    {
        root=getnode(data);  //new node is created with given data and returned as new root
        return root;
    }
    if(data < root->data)
        root->left=insert(root->left,data);  //Recursively inserting the new node with the given data into the left sub-tree if smaller than root->data 
    if(data > root->data)
        root->right=insert(root->right,data);  //Recursively inserting the new node with the given data into the right sub-tree if greater than root->data 
    root=balance(root);  //Function call to balance the tree and assign the balanced tree to root
    return root;
}
//Function to delete predecessor of given node in binary tree
tree del_pred(tree root)
{
    root=root->left;
    while(root->right!=NULL)
        root=root->right;
    return root;
}
//Function deletes a node with given data value from binary tree
tree delete(tree root,int data)
{
    if(root==NULL)
    {
        printf("\nRoot in NUll!\n");
        return NULL;
    }
    if(data < root->data)  //Checking if data to be deleted is less than data of current root node
        root->left=delete(root->left,data);
    else if(data > root->data)  //Checking if data to be deleted is more than data of current root node
        root->right=delete(root->right,data);
    else
    {
        if(root->left==NULL && root->right==NULL)  //If node has no children then it is deleted by freeing the memory 
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)  //If node has no left child then the right child can be used to replace the current node 
        {
            tree temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)  //If node has no right child then the last right child of left child of current node can be used to replace the current node 
        {
            tree temp=root;
            root=root->left;
            free(temp);
        }
        else  //If current node has both left and right child then node to be deleted is replaced with data of predecessor
        {
            tree temp=del_pred(root);
            root->data=temp->data;
            root->left=delete(root->left,temp->data);
        }
    }
    return root;
}
//Display of binary tree in left node,root node ,right node order
void inorder(tree root)
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
void postorder(tree root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
//Function checks whether the binary tree is balanced by comparing the heigths of left and right subtree
int isbalance(tree root)
{
    int left=getheight(root->left);
    int right=getheight(root->right);
    if(left-right==0)
        return 1;
    else
        return 0;
}
int main()
{
    int data,height,check;
    tree root=NULL;
    while(1)
    {
        printf("\n\n1.Insert\n2.Delete\n3.InOrder\n4.PreOrder\n5.PostOrder\n6.Height\n7.Check Balance\n8.Exit\n");
        int ch;
        printf("\nEnter choice:  ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: printf("\nEnter data: ");
                    scanf("%d",&data);
                    root=insert(root,data);  //Function call to insert data into tree
                    break;
            case 2: printf("\nEnter data: ");
                    scanf("%d",&data);
                    root=delete(root,data);  //Function call to delete data from tree
                    break;
            case 3: printf("\nInOrder:\n");
                    inorder(root);  //Function call to display tree in inorder 
                    break;
            case 4: printf("\nPreOrder:\n");
                    preorder(root);  //Function call to display tree in preorder 
                    break;
            case 5: printf("\nPostOrder:\n");
                    postorder(root);  //Function call to display tree in postorder 
                    break;
            case 6: height=getheight(root);  //Function call to display height of tree
                    printf("\nHeight of tree: %d",height); 
                    break;
            case 7: check=isbalance(root);  //Function call to be check whether the tree is balanced or not 
                    if(check)
                        printf("\nTree is balanced.\n");
                    else
                        printf("\nTree is not balanced.\n");
                    break;
            case 8: exit(0);
            default: printf("\nInvalid choice\n");
                    break;
        }
    }
    return 0;
}
