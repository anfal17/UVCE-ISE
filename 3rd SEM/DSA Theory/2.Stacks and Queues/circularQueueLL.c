#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE front = NULL;
NODE rear = NULL;

void enqueue(int x)
{
    NODE newnode = (NODE)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
        rear->next = front;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void display()
{
    NODE temp;
    if (front == NULL && rear == NULL)
    {
        printf("Empty");
    }
    else
    {
        temp = front;
        while (temp->next != front)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
}

void dequeue()
{
    NODE ptr;

    ptr = front;
    if (front == NULL && rear == NULL)
    {
        printf("Empty");
    }
    else if (front == rear)
    {
        front = rear = NULL;
        free(ptr);
    }
    else
    {
        printf("%d is removed", ptr->data);
        front = front->next;
        rear->next = front;
        free(ptr);
    }
}

void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("Empty");
    }
    printf("%d", front->data);
}
