#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
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
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 40);
    head = insert_at_beginning(head, 10);
    head = insert_at_pos(head, 30, 3);
    display(head);
    return 0;
}

NODE getnode()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->link = NULL;
    return temp;
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
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
    temp->link = NULL;
    return head;
}

NODE insert_at_beginning(NODE head, int data)
{
    if (head == NULL)
    {
        head = getnode();
        head->data = data;
        return head;
    }
    NODE ptr = getnode();
    ptr->data = data;
    ptr->link = head;
    head = ptr;
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
        ptr = ptr->link;
        pos--;
    }
    temp->link = ptr->link;
    ptr->link = temp;
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
    head = head->link;
    free(ptr);
    ptr = NULL;
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
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    prev->link = NULL;
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
        cur = cur->link;
        pos--;
    }
    prev->link = cur->link;
    free(cur);
    cur = NULL;
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
        ptr = ptr->link;
    }
}


//Deleting the entire linked list
NODE delete_list(NODE head)
{
    NODE temp = head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    if (head == NULL)
    {
        printf("Entire list is deleted succssfully");
    }
    return head;
}

//Reverse the linked list
NODE reverse_list(NODE head)
{
    NODE prev = NULL; 
    NODE next = NULL;
    while (head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev; 
    return head;
}




