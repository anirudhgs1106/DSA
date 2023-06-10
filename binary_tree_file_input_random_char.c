#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct TREE
{
    char data;
    struct TREE *left;  
    struct TREE *right;  
};
typedef struct TREE *tree;
//Generate random characters and write into files
void random_char(FILE *fp,int n)
{
    int c;
    char r;
    for(int i=0;i<n;i++)
    {
        c=rand()%52;
        if(c<26)
        {
            r='A'+c;
            fprintf(fp,"%c ",r);
        }
        else
        {
            r='a'+(c-26);
            fprintf(fp,"%c ",r);
        }
    }
}
//Function to create a new node for a binary tree with the given data and return it 
tree getnode(char data)  
{
    tree newn=(tree)malloc(sizeof(struct TREE));
    newn->left=NULL;
    newn->right=NULL;
    newn->data=data;
    return newn;
}
tree insert(tree root,char data)
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
        printf("%c ",root->data);
        fprintf(fp,"%c ",root->data);
        inorder(root->right,fp);
    }
}
//Display of binary tree in root node,left node ,right node order and append into "preorder.txt" file 
void preorder(tree root,FILE *fp)
{
    if(root!=NULL)
    {
        printf("%c ",root->data);
        fprintf(fp,"%c ",root->data);
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
        printf("%c ",root->data);
        fprintf(fp,"%c ",root->data);
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
//Function reads a number from user, generates random characters, inserts them into binary tree.
int main()
{
    flush();
    FILE *fp;
    int n; char data;
    tree root=NULL;
    printf("\nEnter number: ");
    scanf("%d",&n);
    fp=fopen("input_char.txt","w");
    random_char(fp,n);
    fclose(fp);
    fp=fopen("input_char.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%c",&data);
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