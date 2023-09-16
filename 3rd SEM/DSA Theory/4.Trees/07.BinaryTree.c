/*7. Create a binary tree and traverse inorder, preorder and postorder.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define a structure for a node in the binary tree
struct node
{
    int data;
    struct node *lchild; // Pointer to the left child node
    struct node *rchild; // Pointer to the right child node
};
typedef struct node *NODE;

NODE root = NULL;

// Function prototypes
void create(NODE);
int is_lchild(NODE);
int is_rchild(NODE);
void inorder(NODE);
void preorder(NODE);
void postorder(NODE);
NODE getnode();

void main()
{
    clrscr();
    printf("Tree traversals\n");

    // Create the root node
    printf("Enter the data for the root: ");
    root = getnode();
    scanf("%d", &root->data);

    // Create the binary tree
    create(root);

    // Perform inorder traversal
    printf("\nInorder traversal:\n");
    inorder(root);

    // Perform preorder traversal
    printf("\nPreorder traversal:\n");
    preorder(root);

    // Perform postorder traversal
    printf("\nPostorder traversal:\n");
    postorder(root);

    getch();
}

// Function to create a new node
NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->lchild = temp->rchild = NULL;
    return temp;
}

// Function to create the binary tree recursively
void create(NODE root)
{
    if (is_lchild(root))
    {
        root->lchild = getnode();
        printf("Enter the data for left child of %d: ", root->data);
        scanf("%d", &root->lchild->data);
        create(root->lchild);
    }
    if (is_rchild(root))
    {
        root->rchild = getnode();
        printf("Enter the data for right child of %d: ", root->data);
        scanf("%d", &root->rchild->data);
        create(root->rchild);
    }
}

// Function to check if a left child should be created
int is_lchild(NODE root)
{
    int ch;
    printf("Create left child of %d? YES-1 NO-0: ", root->data);
    scanf("%d", &ch);
    if (ch)
        return 1;
    else
        return 0;
}

// Function to check if a right child should be created
int is_rchild(NODE root)
{
    int ch;
    printf("Create right child of %d? YES-1 NO-0: ", root->data);
    scanf("%d", &ch);
    if (ch)
        return 1;
    else
        return 0;
}

// Function to perform inorder traversal of the binary tree
void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->lchild);
        printf("%d=>", root->data);
        inorder(root->rchild);
    }
}

// Function to perform preorder traversal of the binary tree
void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d=>", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

// Function to perform postorder traversal of the binary tree
void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d=>", root->data);
    }
}
