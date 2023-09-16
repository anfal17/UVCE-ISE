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

    if (front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
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
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
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
    else
    {
        printf("%d is removed", ptr->data);
        free(ptr);
        front = front->next;
    }
}

void peek()
{
    if (front == NULL && rear == NULL)
    {
        printf("Empty");
    }
    printf("%d",front->data);
}

