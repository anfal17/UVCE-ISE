/*5. Write a program to implement circular linked list using header node
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct node
{
    int data;
    struct node *link;
};
typedef struct node *NODE;

// Function prototypes
NODE insert_rear(NODE);
NODE insert_front(NODE);
NODE delete_front(NODE);
NODE delete_rear(NODE);
NODE getnode();
void display(NODE);

void main()
{
    NODE head;
    int option;
    clrscr(); // Clear the screen
    head = getnode(); // Create a header node
    head->link = head; // Initialize the header node's link to itself, creating an empty circular linked list

    while (1)
    {
        printf("\nCircular linked list operations\n");
        printf("1.Insert to rear\n2.Insert to front\n3.Delete from front\n4.Delete from rear\n5.Display\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            head = insert_rear(head); // Call the function to insert a node at the rear
            getch(); // Wait for a key press
            break;
        case 2:
            head = insert_front(head); // Call the function to insert a node at the front
            getch();
            break;
        case 3:
            head = delete_front(head); // Call the function to delete a node from the front
            getch();
            break;
        case 4:
            head = delete_rear(head); // Call the function to delete a node from the rear
            getch();
            break;
        case 5:
            display(head); // Call the function to display the circular linked list
            getch();
            break;
        case 6:
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

// Function to insert a node at the front of the circular linked list
NODE insert_front(NODE head)
{
    NODE temp;
    temp = getnode(); // Create a new node
    printf("Enter the data: ");
    scanf("%d", &temp->data); // Read data for the new node
    printf("%d is successfully inserted\n", temp->data);
    temp->link = head->link; // Update the links to insert at the front
    head->link = temp;
    return head;
}

// Function to delete a node from the front of the circular linked list
NODE delete_front(NODE head)
{
    NODE ptr;
    if (head->link == head) // Check if the list is empty
    {
        printf("No nodes\n");
        return head;
    }
    ptr = head->link; // Get the first node
    printf("%d is successfully deleted\n", ptr->data);
    head->link = ptr->link; // Update the link to skip the first node
    free(ptr); // Free the memory of the deleted node
    return head;
}

// Function to insert a node at the rear of the circular linked list
NODE insert_rear(NODE head)
{
    NODE ptr, temp;
    ptr = head->link;
    while (ptr->link != head) // Traverse to the last node
        ptr = ptr->link;
    temp = getnode(); // Create a new node
    printf("Enter the data: ");
    scanf("%d", &temp->data); // Read data for the new node
    printf("%d is successfully inserted\n", temp->data);
    ptr->link = temp; // Update the link to insert at the rear
    temp->link = head;
    return head;
}

// Function to delete a node from the rear of the circular linked list
NODE delete_rear(NODE head)
{
    NODE ptr, prev;
    if (head->link == head) // Check if the list is empty
    {
        printf("No nodes\n");
        return head;
    }
    ptr = head->link;
    while (ptr->link != head) // Traverse to the last node
    {
        prev = ptr;
        ptr = ptr->link;
    }
    printf("%d is successfully deleted\n", ptr->data);
    prev->link = head; // Update the link to skip the last node
    free(ptr); // Free the memory of the deleted node
    return head;
}

// Function to display the circular linked list
void display(NODE head)
{
    NODE temp;
    if (head->link == head) // Check if the list is empty
        printf("No nodes\n");
    else
    {
        for (temp = head->link; temp->link != head; temp = temp->link) // Traverse and print all nodes
            printf("%d=>", temp->data);
        printf("%d", temp->data); // Print the last node
    }
}
