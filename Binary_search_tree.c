#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *Create_node()
{
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    printf("\nEnter the data: ");
    scanf("%d", &temp->data);

    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void create_BST(struct tree *root)
{
    struct tree *temp;
    struct tree *ptr;
    char ch;

    do
    {
        /* code */

        temp = Create_node();
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            ptr = root;
            while (ptr != NULL)
            {
                if (temp->data < ptr->data)
                {
                    if (ptr->left == NULL)
                    {
                        ptr->left = temp;
                        break;
                    }
                    else
                    {
                        ptr = ptr->left;
                    }
                }
                else if (temp->data > ptr->data)
                {
                    if (ptr->right == NULL)
                    {
                        ptr->right = temp;
                        break;
                    }
                    else
                    {
                        ptr = ptr->right;
                    }
                }
            }
        }
        printf("Do you want to add more nodes [Y/N]:");
        ch = getche();
    } while (ch == 'y' || ch == 'Y');
}

void inOrder_traversal(struct tree *root)
{
    if (root != NULL)
    {
        inOrder_traversal(root->left);
        printf("%d -> ", root->data);
        inOrder_traversal(root->right);
    }
}

void preOrder_traversal(struct tree *root)
{
    if (root != NULL)
    {
        printf("%d -> ", root->data);
        preOrder_traversal(root->left);
        preOrder_traversal(root->right);
    }
}
void postOrder_traversal(struct tree *root)
{
    if (root != NULL)
    {
        postOrder_traversal(root->left);
        postOrder_traversal(root->right);
        printf("%d -> ", root->data);
    }
}

// int isBst(struct tree *root)
// {
//     static struct tree *prev = NULL;
//     if (root != NULL)
//     {
//         if (!isBst(root->left))
//         {
//             return 0;
//         }
//         if(prev != NULL && root->data <= prev->data)
//         {
//                 return 0;
//         }
//         prev  = root;
//         return isBst(root->right);
//     }
//     else
//     {
//         return 1;
//     }
// }

int isBst(struct tree *root)
{
    static struct tree *prev = NULL;
    if (root != NULL)
    {
        if (!isBst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBst(root->right);
    }
    else
    {
        return 1;
    }
}

struct tree *search(struct tree *root, int value)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == value)
    {
        return root;
    }
    if (root->data > value)
    {
        return search(root->left, value);
    }
    if (root->data < value)
    {
        return search(root->right, value);
    }
}
struct tree *search_iterative(struct tree *root, int value)
{
    while (root != NULL)
    {

        if (value == root->data)
        {
            return root;
        }
        else if (value < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}
void insert(struct tree *root)
{
    struct tree *ptr = Create_node();
    struct tree *prev;
    while (root != NULL)
    {
        prev = root;
        if (ptr->data == root->data)
        {
            printf("Cannot insert, %d is already in BST.");
            return;
        }
        else if (ptr->data < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    if (ptr->data < prev->data)
    {
        prev->left = ptr;
    }
    else
    {
        prev->right = ptr;
    }
}
struct tree *inOrderpredecessor(struct tree *root)
{
    //Function returns the inOrder Predecessor of deleting node.
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
    
}
struct tree *delete_node(struct tree *root,int value)
{
    struct tree *ipre;
    //base condition
    if(root == NULL)
    {
        return NULL;
    }
    if(root->left ==  NULL && root->right ==NULL)
    {
        free(root);
        return NULL;
    }
    // locate the node to be delete
    if(value < root->data)
    {
        root->left = delete_node(root->left,value);
    }
    else if(value > root->data)
    {
        root->right = delete_node(root->right,value);
    }
    //delete the node when it is found
    else
    {
        ipre = inOrderpredecessor(root);
        root->data = ipre->data;
        root->left = delete_node(root->left,ipre->data);
    }
    return root;

}
int main()
{

    int res;
    int choice;
    struct tree *ptr;
    int value;
    printf("Enter the root data: ");
    struct tree *root = Create_node();
    do
    {
        printf("\n1.Create Binary Search tree \n2.Inorder traversal\n3.PreOrder traversal\n4.postOrder traversal\n5.is Bst\n6.Search a node\n7.Iterative search\n8.Insert in a tree\n9.Delete the node of tree\n10.exit\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_BST(root);
            //     6
            //    / \
            //   4   8
            //  / \  
            // 2  5
            break;

        case 2:
            inOrder_traversal(root);
            break;

        case 3:
            preOrder_traversal(root);
            break;
        case 4:
            postOrder_traversal(root);
            break;
        case 5:
            printf("%d ", isBst(root));
            break;
        case 6:

            printf("\nEnter the value to be search: ");
            scanf("%d", &value);
            ptr = search(root, value);
            if (ptr != NULL)
            {
                printf("\n%d is found ", ptr->data);
            }
            else
            {
                printf("\n%d is not found! ");
            }
            break;
        case 7:

            printf("\nEnter the value to be search: ");
            scanf("%d", &value);
            ptr = search_iterative(root, value);
            if (ptr != NULL)
            {
                printf("\n%d is found ", ptr->data);
            }
            else
            {
                printf("\n%d is not found! ");
            }
            break;
        case 8:

            insert(root);
            break;
        case 9:
            printf("\nEnter the value to be search: ");
            scanf("%d", &value);
            delete_node(root, value);
            break;
        }

    } while (choice != 10);
}