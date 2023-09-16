/*1 a. Implement stacks using arrays:*/

#include <stdio.h>
#include <stdlib.h>
#define size 3

int stack[size]; // Initialize the stack array

// Function prototypes
int push(int top);
int pop(int top);
void display(int top);

int main()
{
    int top = -1, option;

    while (1)
    {
        printf("\nStack Operations\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            top = push(top); // Call the push function and update the top of the stack
            break;
        case 2:
            top = pop(top); // Call the pop function and update the top of the stack
            break;
        case 3:
            display(top); // Call the display function
            break;
        case 4:
            exit(0); // Exit the program
            break;
        default:
            printf("\nInvalid Option\n");
            break;
        }
    }
}

int push(int top)
{
    int item;
    if (top == (size - 1))
    {
        printf("Stack is Full\n");
        return top;
    }
    printf("Enter the item to be pushed: ");
    scanf("%d", &item);
    stack[++top] = item; // Increment the top and push the item onto the stack
    printf("%d is pushed Successfully", item);
    return top; // Return the updated top
}

int pop(int top)
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return top;
    }
    printf("%d is deleted ", stack[top]); // Display the item being popped
    top--; // Decrement the top to remove the item
    return top; // Return the updated top
}

void display(int top)
{
    int i;
    if (top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Status of stack\n");
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]); // Display the stack elements from top to bottom
        }
    }
}
