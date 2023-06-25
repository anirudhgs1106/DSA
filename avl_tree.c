#include <stdio.h>
#include <stdlib.h>
struct TREE
{
    int data;
    struct TREE *left,*right;
};
typedef struct TREE *tree;
//Generate random integers and write into files
void random_gen(FILE *fp,int n)
{
    int x,y,c,d;
    printf("\nEnter range x,y: ");
    scanf("%d%d",&x,&y);
    d=(x+y)/2;
    for(int i=0;i<n;i++)
    {
        label: c=rand()%y;
        if(c>x && c<y)
            fprintf(fp,"%d ",c);
        else    
            goto label;
    }
}
//Function to calculate the height of the tree
int getheight(tree root)
{
    if(root==NULL)
    {
        return -1;
    }
    else
    {
        int leftheight=getheight(root->left);
        int rightheight=getheight(root->right);
        if(leftheight>rightheight)
            return leftheight+1;
        else
            return rightheight+1;
    }
}
//Function to perform left rotation on a binary tree
tree rotate_left(tree root)
{
    tree newn=root->right;
    root->right=newn->left;
    newn->left=root;
    return newn;  //Returning new root of subtree after performing a left rotation
}
//Function to perform right rotation on a binary tree
tree rotate_right(tree root)
{
    tree newn=root->left;
    root->left=newn->right;
    newn->right=root;
    return newn;  //Returning new root of subtree after performing a right rotation
}
//Function to perform rotation based on height of subtree's
tree balance(tree root)
{
    int balance=getheight(root->left)-getheight(root->right);
    if(balance > 1 && (getheight(root->left->left) >= getheight(root->left->right))) 
        return rotate_right(root);  //If true, left tree has more elements and right rotation is performed to balance
    if(balance < -1 && (getheight(root->right->right) >= getheight(root->right->left)))  
        return rotate_left(root);  //If true, right tree has more elements and left rotation is performed to balance
    if(balance > 1 && (getheight(root->left->left) < getheight(root->left->right))) 
    {
        root->left=rotate_left(root->left);  //If true, left subtree has more elements on right side therefore
        return rotate_right(root);           //left rotation and right rotation are performed for balancing
    }
    if(balance < -1 && (getheight(root->right->right) < getheight(root->right->left)))
    {
        root->right=rotate_right(root->right);  //If true, right subtree has more elements on left side therefore
        return rotate_left(root);               //right rotation and left rotation are performed for balancing
    }
    return root;
}
//Function to create a new node for a binary tree with the given data and return it 
tree getnode(int data)
{
    tree newn=(tree)malloc(sizeof(struct TREE));
    newn->data=data;
    newn->left=NULL;
    newn->right=NULL;
    return newn;
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
    root=balance(root);
    return root;
}
//Display of binary tree in left node,root node ,right node order and append into "inorder.txt" file 
void inorder(tree root,FILE *fp1)
{
    if(root!=NULL)
    {
        inorder(root->left,fp1);
        printf("%d ",root->data);
        fprintf(fp1,"%d ",root->data);  //Prints in-order output in "inorder.txt" file
        inorder(root->right,fp1);
    }
}
//Display of binary tree in root node,left node ,right node order and append into "preorder.txt" file 
void preorder(tree root,FILE *fp2)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        fprintf(fp2,"%d ",root->data);  //Prints pre-order output in "preorder.txt" file
        preorder(root->left,fp2);
        preorder(root->right,fp2);
    }
}
//Display of binary tree in left node,right node,root node order and append into "postorder.txt" file 
void postorder(tree root,FILE *fp3)
{
    if(root!=NULL)
    {
        postorder(root->left,fp3);
        postorder(root->right,fp3);
        printf("%d ",root->data);
        fprintf(fp3,"%d ",root->data);  //Prints post-order output in "postorder.txt" file
    }
}

void flush()
{
    FILE *fp;
    fp=fopen("inorder.txt","w");
    fclose(fp);
    fp=fopen("preorder.txt","w");
    fclose(fp);
    fp=fopen("postorder.txt","w");
    fclose(fp);
}
//The function generates random number's and prints into file, creates binary tree from fike and displays output in in-order,pre-order and post-order.  
int main()
{
    flush();
    FILE *fp,*fp1,*fp2,*fp3;
    int n,data;
    tree root=NULL;
    printf("\nEnter number: ");
    scanf("%d",&n);
    fp=fopen("input.txt","w");
    random_gen(fp,n);
    fclose(fp);
    fp=fopen("input.txt","r");
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&data);
        root=insert(root,data);
    }
    fclose(fp);
    fp1=fopen("inorder.txt","a");
    fp2=fopen("preorder.txt","a");
    fp3=fopen("postorder.txt","a");
    printf("\nIn-Order:\n");
    inorder(root,fp1);
    printf("\nPre-Order:\n");
    preorder(root,fp2);
    printf("\nPost-Order:\n");
    postorder(root,fp3);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}
