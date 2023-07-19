//Symbolic Differentiation
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
void postorder(tree root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ",root->data);
    }
}
void symbolic(tree root)
{
    if(root!=NULL)
    {
        symbolic(root->left);
        symbolic(root->right);
        if(isalpha(root->data))
            printf("d%c/dx ",root->data);
        else
            printf("d%c ",root->data);
    }
}
tree expression_tree(char postfix[])
{
    int i=0;
    tree newn=getnode(postfix[i]);
    if(isalpha(postfix[i]))
        return newn;
    i++;
    newn->right=expression_tree(postfix);
    i++;
    newn->left=expression_tree(postfix);
    return newn;
}
int main()
{
    char postfix[]="ab+cd-*";
    tree root=NULL;
    root=expression_tree(postfix);
    printf("\nExpression Tree: ");
    postorder(root);
    printf("\nSymbolic Differentiation: ");
    symbolic(root);
    return 0;
}
/*
Expression Tree: a 
Symbolic Differentiation: da/dx  
*/