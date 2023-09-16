#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int front = -1;
int rear = -1;

int queue[SIZE];

void enqueue(int item)
{
    int pos;
    if (rear == SIZE - 1)
    {
        printf("\nQueue is Full");
    }
    else
    {
        pos = rear;
        rear++;
        while (pos >= 0 && queue[pos] >= item)
        {
            queue[pos + 1] = queue[pos];
            pos--;
        }
        queue[pos + 1] = item;
        if (front == -1)
        {
            front++;
            return;
        }
    }
}

void dequeue()
{
    int del;
    if (front == -1 && rear == -1)
    {
        printf("\nQueue Empty");
    }
    else
    {
        printf("Deleted element is : %d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
            return;
        }
        front++;
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Empty queue\n");
    }
    else
    {
        int i = front;
        while (i <= rear)
        {
            printf("%d=>", queue[i]);
            i++;
        }
        printf("\n");
    }
}

int main()
{
    enqueue(5);
    enqueue(2);
    enqueue(6);
    enqueue(4);
    display();
    enqueue(-1);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    display();
    enqueue(4);
    enqueue(2);
    enqueue(7);
    enqueue(1);
    display();
    return 0;
}


/*
In normal queues we delete and insert from front and rear but, in priority queue deletion is done according to the priority

2 Types Of Priority Queue
1.Ascending PQ - element having lesser value has (higher priority) and is deleted first
2.Descending PQ - element having highest priority deleted first ,based on higher value

Implemented in 2 ways
1st way - above program 
    1.Special Insertion - sorted
    2.Normal deletion
2nd way
    1.Normal Insertion
    2.Special deletion - search and delete higher priority element first
*/