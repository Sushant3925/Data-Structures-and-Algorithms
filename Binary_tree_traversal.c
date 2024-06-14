#include<stdio.h>
#include<stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;

};

struct tree *newNode()
{
    struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
    printf("Enter the data: ");
    scanf("%d",&temp->data);

    temp->left = NULL;
    temp->right = NULL;
    return temp; 
}
void postOrder_traversal(struct tree *root)
{
    if(root != NULL)
    {
        postOrder_traversal(root->left);
        postOrder_traversal(root->right);
        printf("%d -> ",root->data);

    }

}
void preOrder_traversal(struct tree *root)
{
    if(root != NULL)
    {
        printf("%d -> ",root->data);
        preOrder_traversal(root->left);
        preOrder_traversal(root->right);
        
    }
}
void inOrder_traversal(struct tree *root)
{
    if(root != NULL)
    {
        inOrder_traversal(root->left);
        printf("%d -> ",root->data);
        inOrder_traversal(root->right);
        
    }
}
int main()
{
    struct tree *root = newNode();
    struct tree *left = newNode();
    struct tree *right = newNode();
    struct tree *left1 = newNode();
    struct tree *right1 = newNode();

    root->left = left;
    root->right = right;

    // 
    //     4
    //    / \
    //   1   6   
    //  / \  
    // 5   2
    left->left = left1;
    left->right = right1;

    printf("\nInorder Traversal   :");   // 5 -> 1 -> 2 -> 4 -> 6
    inOrder_traversal(root);

    printf("\nPostorder Traversal :"); // 5 -> 2 -> 1 -> 6 -> 4
    postOrder_traversal(root);

    printf("\nPreorder Traversal  :");  //4 -> 1 -> 5 -> 2 -> 6 
    preOrder_traversal(root);


}