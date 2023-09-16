/*6.Write a program to implement doubly linked list:*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct node
{
    int data;
    struct node *llink; // Pointer to the previous node (left link)
    struct node *rlink; // Pointer to the next node (right link)
};
typedef struct node *NODE;

// Function prototypes
NODE insert_pos(NODE);
NODE delete_pos(NODE);
NODE delete_front(NODE);
NODE insert_rear(NODE);
void display(NODE);
NODE getnode();

void main()
{
    NODE first = NULL; // Initialize the doubly linked list as empty
    int option;
    while (1)
    {
        printf("\nDoubly linked list operations\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("1.Insert rear\n2.Insert position\nEnter your choice:");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                first = insert_rear(first); // Call the function to insert at the rear
                getch();                    // Wait for a key press
                break;
            case 2:
                first = insert_pos(first); // Call the function to insert at a specific position
                getch();
                break;
            default:
                printf("Invalid choice\n");
            }
            break;
        case 2:
            first = delete_pos(first); // Call the function to delete a node at a specific position
            getch();
            break;
        case 3:
            display(first); // Call the function to display the doubly linked list
            getch();
            break;
        case 4:
            exit(0); // Exit the program
        default:
            printf("Invalid choice\n");
        }
    }
}

// Function to create a new node
NODE getnode()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node)); // Allocate memory for a new node
    return temp;
}

// Function to insert a node at a specific position in the doubly linked list
NODE insert_pos(NODE first)
{
    int pos, count;
    NODE temp, ptr;
    temp = getnode();                 // Create a new node
    temp->llink = temp->rlink = NULL; // Initialize left and right links as NULL
    if (first == NULL)
    {
        printf("Enter the data: ");
        scanf("%d", &temp->data); // Read data for the new node
        printf("%d is successfully inserted\n", temp->data);
        first = temp; // If the list is empty, make the new node the first node
        return first;
    }
    count = 1;
    printf("Enter the position: ");
    scanf("%d", &pos); // Read the position where the node should be inserted
    ptr = first;
    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
        count++; // Count the number of nodes in the list
    }
    if (pos > count)
    {
        printf("Invalid position\n"); // Check for invalid position
        return first;
    }
    printf("Enter the data: ");
    scanf("%d", &temp->data); // Read data for the new node
    printf("%d is successfully inserted\n", temp->data);
    if (pos == 1)
    {
        temp->rlink = first;
        first->llink = temp;
        first = temp; // Insert at the front of the list
        return first;
    }
    ptr = first;
    count = 1;
    while (count < pos)
    {
        ptr = ptr->rlink;
        count++;
    }
    ptr->llink->rlink = temp;
    temp->llink = ptr->llink;
    temp->rlink = ptr;
    ptr->llink = temp; // Insert at the specified position
    return first;
}

// Function to delete a node at a specific position in the doubly linked list
NODE delete_pos(NODE first)
{
    NODE ptr;
    int pos, count;
    if (first == NULL)
    {
        printf("No nodes\n");
        return first;
    }
    ptr = first;
    count = 1;
    while (ptr->rlink != NULL)
    {
        ptr = ptr->rlink;
        count++; // Count the number of nodes in the list
    }
    printf("Enter the position: ");
    scanf("%d", &pos); // Read the position to delete a node
    if (pos > count)
    {
        printf("Invalid position\n"); // Check for invalid position
        return first;
    }
    if (pos == 1)
    {
        first = delete_front(first); // Call the function to delete the front node
        return first;
    }
    ptr = first;
    count = 1;
    while (count < pos)
    {
        ptr = ptr->rlink;
        count++;
    }
    printf("%d is successfully deleted\n", ptr->data);
    ptr->llink->rlink = ptr->rlink;
    ptr->rlink->llink = ptr->llink;
    free(ptr); // Delete the node at the specified position
    return first;
}

// Function to display the doubly linked list
void display(NODE first)
{
    NODE temp;
    if (first == NULL)
        printf("No nodes\n");
    else
    {
        for (temp = first; temp->rlink != NULL; temp = temp->rlink)
            printf("%d=>", temp->data); // Traverse and print all nodes
        printf("%d", temp->data);       // Print the last node
    }
}

// Function to insert a node at the rear of the doubly linked list
NODE insert_rear(NODE first)
{
    NODE temp, ptr;
    temp = getnode(); // Create a new node
    printf("Enter the data: ");
    scanf("%d", &temp->data); // Read data for the new node
    printf("%d is successfully inserted\n", temp->data);
    temp->rlink = temp->llink = NULL; // Initialize left and right links as NULL
    if (first == NULL)
    {
        first = temp;
        return first;
    }
    ptr = first;
    while (ptr->rlink != NULL)
        ptr = ptr->rlink;
    ptr->rlink = temp;
    temp->llink = ptr; // Insert at the rear of the list
    return first;
}

// Function to delete the front node of the doubly linked list
NODE delete_front(NODE first)
{
    NODE ptr;
    ptr = first;
    first->rlink->llink = NULL;
    first = first->rlink;
    printf("%d is successfully deleted", ptr->data);
    free(ptr); // Delete the front node
    return first;
}
