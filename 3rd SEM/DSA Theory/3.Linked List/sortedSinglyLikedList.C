#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE insert(NODE, int);
void print(NODE);

int main()
{
    NODE head = NULL;
    head = insert(head, 10);
    head = insert(head, 5);
    head = insert(head, 20);
    head = insert(head, 15);
    head = insert(head, 7);

    print(head);
    return 0;
}

NODE getnode(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    return temp;
}

NODE insert(NODE head, int data)
{
    NODE temp = head;
    NODE newP = getnode(data);
    int key = data;
    if (head == NULL || key < head->data)
    {
        newP->link = head;
        head = newP;
        return head;
    }
    temp = head;
    while (temp->link != NULL && temp->link->data < key)
    {
        temp = temp->link;
    }
    newP->link = temp->link;
    temp->link = newP;
    return head;
}

void print(NODE head)
{
    NODE temp = head;

    while (temp != NULL)
    {
        printf("%d=>", temp->data);
        temp = temp->link;
    }
}
