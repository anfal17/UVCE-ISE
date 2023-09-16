#include <stdio.h>
#include <stdlib.h>
#define N 5

int front = -1;
int rear = -1;
int queue[N];

void enqueue(int x)
{
    if (front == -1 & rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if ((rear + 1) % N == front)
    {
        printf("Queue Full");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 & rear == -1)
    {
        printf("Queue Empty");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("Dequeued Element %d", queue[front]);
        front = (front + 1) % N;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Empty queue");
    }
    else
    {
        int i = front;
        while (i != rear)
        {
            printf("%d=>", queue[i]);
            i = (i + 1) % N;
        }
    }
}

void main()
{
    enqueue(5);
    enqueue(-1);
    dequeue();
    enqueue(4);
    enqueue(2);
    enqueue(7);
    enqueue(1);
}
