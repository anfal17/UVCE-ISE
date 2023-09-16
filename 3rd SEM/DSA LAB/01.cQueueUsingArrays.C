/*1 b.Implement Queues using Arrays:*/

#include <stdio.h>
#include <stdlib.h>
#define size 3
int rear = -1, front = -1, queue[20];

// Function prototypes
void qinsert();
void qdelete();
void qdisplay();

int main()
{
    int ch = 1, option;

    while (ch)
    {
        printf("Queue Operations\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            qinsert(); // Call the insert function
            break;
        case 2:
            qdelete(); // Call the delete function
            break;
        case 3:
            qdisplay(); // Call the display function
            break;
        case 4:
            exit(0); // Exit the program
        default:
            printf("Invalid Choice\n");
            break;
        }
    }

    return 0;
}

void qinsert()
{
    int num;
    if (rear == (size - 1))
    {
        printf("Queue is full\n");
        return;
    }
    printf("Enter the element to insert: ");
    scanf("%d", &num);
    queue[++rear] = num;
    printf("%d is successfully inserted\n", num);
    if (front == -1)
    {
        front++;
    }
    return;
}

void qdelete()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    if (front == rear)
    {
        printf("Deleted element : %d", queue[front]);
        front = -1;
        rear = -1;
        return;
    }

    printf("Deleted element : %d", queue[front]);
    front++;
    return;
}

void qdisplay()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Status of Queue is \n");
    for (i = front; i <= rear; i++)
    {
        printf("%d\t", queue[i]);
    }
    return;
}
