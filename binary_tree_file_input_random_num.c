//Binary tree
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
    newn->left=NULL;
    newn->right=NULL;
    newn->data=data;
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
    return root;
}
//Display of binary tree in left node,root node ,right node order and append into "inorder.txt" file 
void inorder(tree root,FILE *fp)
{
    if(root!=NULL)
    {
        inorder(root->left,fp);
        printf("%d\t",root->data);
        fprintf(fp,"%d ",root->data);
        inorder(root->right,fp);
    }
}
//Display of binary tree in root node,left node ,right node order and append into "preorder.txt" file 
void preorder(tree root,FILE *fp)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        fprintf(fp,"%d ",root->data);
        preorder(root->left,fp);
        preorder(root->right,fp);
    }
}
//Display of binary tree in left node,right node,root node order and append into "postorder.txt" file 
void postorder(tree root,FILE *fp)
{
    if(root!=NULL)
    {
        postorder(root->left,fp);
        postorder(root->right,fp);
        printf("%d\t",root->data);
        fprintf(fp,"%d ",root->data);
    }
}
//Generate random integers and write into files
void random_gen(FILE *fp,int n)
{
    int c,x,y;
    printf("\nEnter range x and y:");
    scanf("%d%d",&x,&y);
    for(int i=0;i<n;i++)
    {
        label: c=rand()%y;
        if(c<y && c>x)
        {
            fprintf(fp,"%d ",c);
        }
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
//Function reads a number from user, generates random numbers, inserts them into binary tree.
int main()
{
    flush();
    FILE *fp;
    int n,data;
    tree root=NULL;
    fp=fopen("input.txt","w");
    printf("\nEnter number:  ");
    scanf("%d",&n);
    random_gen(fp,n);
    fclose(fp);
    fp=fopen("input.txt","r");
    for(int i=0;i<n;i++)
    {
        fscanf(fp,"%d",&data);
        root=insert(root,data);
    }
    fclose(fp);
    fp=fopen("inorder.txt","a");
    printf("\nIn-Order\n");
    inorder(root,fp);  
    fclose(fp);
    fp=fopen("preorder.txt","a");
    printf("\nPre-Order\n");
    preorder(root,fp); 
    fclose(fp);
    fp=fopen("postorder.txt","a");
    printf("\nPost-Order\n");
    postorder(root,fp);
    fclose(fp);
    return 0;
}