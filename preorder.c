//Decision Tree using PreOrder
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct TREE 
{
    char data; 
    struct TREE *left,*right;
};
typedef struct TREE *tree;
tree getnode(char data)
{
    tree newn=(tree)malloc(sizeof(struct TREE));
    newn->left=NULL;
    newn->right=NULL;
    newn->data=data;
    return newn;
}
void preorder(tree root)
{
    if(root!=NULL)
    {
        printf("%c ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void decision_tree(tree root)
{
    if(root==NULL)
        return;
    printf("\nEnter 'Y if feature %c is presenent otherwise 'N':",root->data);
    char choice;
    scanf(" %c",&choice);
    if(choice=='Y')
    {
        root->left=getnode('Y');
        decision_tree(root->left);
    }
    else if(choice=='N')
    {
        root->right=getnode('N');
        decision_tree(root->right);
    }
    else
    {
        printf("\nInvalid Choice.\n");
        decision_tree(root);
    }
}
int main()
{
    tree root=NULL;
    root=getnode('A');
    decision_tree(root);
    printf("\nDecision Tree: ");
    preorder(root);
    return 0;
}
/*
Enter 'Y' if feature A is present, 'N' otherwise: Y
Enter 'Y' if feature Y is present, 'N' otherwise: N
Enter 'Y' if feature N is present, 'N' otherwise: N
Enter 'Y' if feature Y is present, 'N' otherwise: Y
Enter 'Y' if feature N is present, 'N' otherwise: N
Enter 'Y' if feature Y is present, 'N' otherwise: N

Decision Tree (Pre-order traversal): A Y N Y N 
*/