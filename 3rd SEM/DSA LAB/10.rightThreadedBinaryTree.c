/*10. Create Right in threaded binary tree:*/

#include <conio.h>
#include <stdio.h>

// Define the structure for a threaded binary tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int RT; // Right Thread flag
};

typedef struct node *NODE;
NODE head = 0;

// Function prototypes
NODE create(int, NODE);
void insert_left(int, NODE);
void insert_right(int, NODE);
void inorder(NODE);
NODE inorder_successor(NODE);

int ch, i, n, item, choice;

void main()
{
    NODE head;
    clrscr();

    // Initialize the head node for the threaded binary tree
    head = (NODE)malloc(sizeof(struct node));
    head->right = head;
    head->left = 0;
    head->RT = 0;

    while (1)
    {
        printf("\n1.Create tree\n2.Inorder\n3.Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the number of nodes to create: ");
            scanf("%d", &n);

            // Loop to create nodes and build the threaded binary tree
            for (i = 1; i < n + 1; i++)
            {
                printf("Enter data %d: ", i);
                scanf("%d", &item);
                head = create(item, head);
            }
            break;
        case 2:
            inorder(head); // Traverse and display the threaded binary tree in inorder
            break;
        case 3:
            exit(0); // Exit the program
        default:
            printf("Wrong choice\n");
            break;
        }
    }
}

// Function to create and insert a new node into the threaded binary tree
NODE create(int item, NODE head)
{
    NODE curptr, ptr;

    // If the tree is empty, insert the new node as the left child of the head
    if (head->left == 0)
    {
        insert_left(item, head);
        return (head);
    }

    curptr = head->left;

    // Traverse the tree to find the appropriate position for the new node
    while (curptr != head)
    {
        ptr = curptr;
        if (item < (curptr->data))
        {
            if (curptr->left != 0)
                curptr = curptr->left;
            else
                break;
        }
        else
        {
            if (item > (curptr->data))
            {
                if (curptr->RT == 0)
                    curptr = curptr->right;
                else
                    break;
            }
        }
    }

    // Insert the new node into the tree based on its value and threading flags
    if (item < (curptr->data))
    {
        insert_left(item, ptr);
        return (head);
    }
    else
    {
        if (item > (curptr->data) && curptr->RT == 1)
            insert_right(item, ptr);
    }

    return (head);
}

// Function to insert a new node as the left child of a given node
void insert_left(int item, NODE ptr)
{
    NODE temp, newnode;

    // Create a new node for the data and initialize its fields
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->left = 0;
    newnode->data = item;

    // Update the left and right pointers for the new node
    ptr->left = newnode;
    newnode->right = ptr;
    newnode->RT = 1; // Set the Right Thread flag to indicate threading
}

// Function to insert a new node as the right child of a given node
void insert_right(int item, NODE ptr)
{
    NODE temp, newnode;

    // Create a new node for the data and initialize its fields
    newnode = (NODE)malloc(sizeof(struct node));
    newnode->left = 0;
    newnode->data = item;
    temp = ptr->right;

    // Update the right pointers for the new node and the next node in the thread
    ptr->right = newnode;
    newnode->right = temp;
    ptr->RT = 0;         // Reset the Right Thread flag
    newnode->RT = 1;     // Set the Right Thread flag for the new node
}

// Function to perform an inorder traversal of the threaded binary tree
void inorder(NODE head)
{
    NODE temp;

    // Check if the tree is empty
    if (head->left == 0)
    {
        printf("\n No nodes");
        return;
    }
    temp = head;

    // Traverse the threaded binary tree in inorder using threading
    while (1)
    {
        temp = inorder_successor(temp);

        // If the successor is the head, we have completed the traversal
        if (temp == head)
            return;

        // Print the data of the current node and continue to the next node
        printf("%d=>", temp->data);
    }
}

// Function to find the inorder successor of a given node in a threaded binary tree
NODE inorder_successor(NODE ptr)
{
    NODE temp;
    temp = ptr->right;

    // If the Right Thread flag is set, return the right child as the successor
    if (ptr->RT == 1)
        return (temp);

    // Otherwise, find the leftmost node in the right subtree
    while (temp->left != 0)
        temp = temp->left;

    return (temp);
}
