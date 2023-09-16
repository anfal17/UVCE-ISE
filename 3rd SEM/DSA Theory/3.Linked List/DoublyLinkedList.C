#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE getnode();
NODE insert_at_end(NODE, int);
NODE insert_at_beginning(NODE, int);
NODE insert_at_pos(NODE, int, int);
NODE delete_at_end(NODE);
NODE delete_at_beginning(NODE);
NODE delete_at_pos(NODE, int);
void display(NODE);

int main()
{
    NODE head = NULL;
    // head = insert_at_end(head, 20);
    head = insert_at_end(head, 40);
    head = insert_at_beginning(head, 10);
    head = insert_at_beginning(head, 20);
    head = insert_at_pos(head, 30, 3);
    display(head);
    return 0;
}

NODE getnode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->next = temp->prev = NULL;
    return temp;
}

NODE insert_at_beginning(NODE head, int data)
{
    if (head == NULL)
    {
        head = getnode();
        head->data = data;
        return head;
    }
    NODE temp = getnode();
    temp->data = data;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}


NODE insert_at_end(NODE head, int data)
{
    if (head == NULL)
    {
        head = getnode();
        head->data = data;
        return head;
    }
    NODE temp = getnode();
    temp->data = data;
    NODE ptr = NULL;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    temp->next = NULL;
    return head;
}

NODE insert_at_pos(NODE head, int data, int pos)
{
    if (head == NULL)
    {
        head = getnode();
        head->data = data;
        return head;
    }
    NODE ptr, temp;
    temp = getnode();
    temp->data = data;

    if (pos == 1)
    {
        head = insert_at_beginning(head, data);
        return head;
    }

    // traversing
    ptr = head;
    pos--;
    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
    return head;
}



void display(NODE head)
{
    NODE ptr = head;
    if (head == NULL)
    {
        printf("No nodes present!");
    }

    while (ptr != NULL)
    {
        printf("%d => ", ptr->data);
        ptr = ptr->next;
    }
}

NODE delete_at_end(NODE head)
{
    if (head == NULL)
    {
        printf("No nodes present!\n");
        return head;
    }
    NODE cur = head;
    NODE prev = head;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    cur->prev = NULL;
    free(cur);
    cur = NULL;
    return head;
}

NODE delete_at_beginning(NODE head)
{
    if (head == NULL)
    {
        printf("No nodes present!\n");
        return head;
    }
    NODE ptr = head;
    head = head->next;
    free(ptr);
    ptr = NULL;
    head->prev = NULL;
    return head;
}

NODE delete_at_end(NODE head)
{
    if (head == NULL)
    {
        printf("No nodes present!\n");
        return head;
    }
    NODE cur = head;
    NODE prev = head;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    free(cur);
    cur = NULL;
    return head;
}

NODE delete_at_pos(NODE head, int pos)
{
    if (head == NULL)
    {
        printf("No nodes present!\n");
        return head;
    }

    if (pos == 1)
    {
        head = delete_at_beginning(head);
        return head;
    }

    NODE prev, cur;
    cur = head;
    pos--;
    while (pos != 1)
    {
        cur = cur->next;
        pos--;
    }
    prev->next = cur->next;
    cur->next->prev = prev;
    free(cur);
    cur = NULL;
    return head;
}
