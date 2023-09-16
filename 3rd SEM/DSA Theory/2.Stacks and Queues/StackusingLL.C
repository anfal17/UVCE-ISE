#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *top = NULL;

typedef struct node *NODE;

NODE getnode();
void push(int);
int pop();
int isEmpty();
int peek();
void print();

void main()
{
    int choice, data;
    while (1)
    {
        printf("\nStack Operations");
        printf("\n1.Push\n2.Pop\n3.display top\n4.display all\n5.exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed : ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
            data = pop();
            printf("%d is successfully popped ", data);
            break;

        case 3:
            printf("The topmost element of the stack %d", peek());

        case 4:
            print();
            break;

        case 5:
            exit(1);

        default:
            break;
        }
    }
}

NODE getnode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->link = NULL;
    return temp;
}

void push(int data)
{
    NODE newNode = getnode();
    if (newNode == NULL)
    {
        printf("Stack Overflow");
        exit(1);
    }
    newNode->data = data;
    newNode->link = top;
    top = newNode;
}

int pop()
{
    NODE ptr;
    ptr = top;
    if (isEmpty())
    {
        printf("Stack underflow");
        exit(1);
    }

    int val = ptr->data;
    top = ptr->link;
    free(ptr);
    ptr = NULL;
    return val;
}

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int peek()
{
    if (isEmpty())
    {
        printf("Stack underflow");
        exit(1);
    }
    return top->data;
}

void print()
{
    NODE ptr;
    ptr = top;
    printf("The stack elements are");
    if (isEmpty())
    {
        printf("Stack underflow");
        exit(1);
    }
    while (ptr)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
