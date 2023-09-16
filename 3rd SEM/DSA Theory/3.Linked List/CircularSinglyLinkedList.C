#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *NODE;

NODE addToEmpty(int data);
NODE insert_at_first(NODE, int);
NODE insert_after_pos(NODE, int, int);
NODE insert_at_end(NODE, int);
NODE delete_at_first(NODE);
NODE delete_at_end(NODE);
NODE delete_at_pos(NODE, int);
void print(NODE);

int main()
{
    NODE tail;
    tail = addToEmpty(100);

    tail = insert_at_first(tail, 20);
    tail = insert_at_end(tail, 50);
    tail = insert_after_pos(tail, 30, 2);
    tail = insert_after_pos(tail, 76, 2);
    printf("Before deletion ");
    print(tail);

    tail = delete_at_first(tail);
    tail = delete_at_end(tail);
    printf("\nAfter deletion\t");
    print(tail);
    tail = delete_at_pos(tail, 2);
    printf("\nAfter deletion at pos ");
    print(tail);

    return 0;
}

NODE addToEmpty(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

NODE insert_at_first(NODE tail, int data)
{
    NODE newP = addToEmpty(data);
    if (tail == NULL)
    {
        return newP;
    }
    newP->next = tail->next;
    tail->next = newP;
    return tail;
}

NODE insert_at_end(NODE tail, int data)
{
    NODE newP = addToEmpty(data);
    if (tail == NULL)
    {
        return newP;
    }
    newP->next = tail->next;
    tail->next = newP;
    tail = tail->next;
    return tail;
}

NODE insert_after_pos(NODE tail, int data, int pos)
{
    NODE newP = addToEmpty(data);
    NODE ptr = tail->next;
    while (pos > 1)
    {
        ptr = ptr->next;
        pos--;
    }
    newP->next = ptr->next;
    ptr->next = newP;
    if (ptr == tail)
    {
        tail = tail->next;
    }
    return tail;
}

NODE delete_at_first(NODE tail)
{
    if (tail == NULL)
    {
        printf("Empty node");
        return tail;
    }
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    NODE ptr = tail->next;
    tail->next = ptr->next;
    free(ptr);
    ptr = NULL;
    return tail;
}

NODE delete_at_end(NODE tail)
{
    if (tail == NULL)
    {
        printf("Empty node");
        return tail;
    }
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }

    NODE ptr = tail->next;
    while (ptr->next != tail)
    {
        ptr = ptr->next;
    }
    ptr->next = tail->next;
    free(tail);
    tail = ptr;
    return tail;
}

// delete at pos
NODE delete_at_pos(NODE tail, int pos)
{
    if (tail == NULL)
    {
        return tail;
    }
    NODE ptr = tail->next;
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while (pos > 2)
    {
        ptr = ptr->next;
        pos--;
    }
    NODE ptr2 = ptr->next;
    ptr->next = ptr2->next;
    // if ptr2 == tail
    if (ptr2 == tail)
    {
        tail = ptr;
    }
    free(ptr2);
    ptr2 = NULL;
    return tail;
}

void print(NODE tail)
{
    NODE ptr = tail->next;
    do
    {
        printf("%d=>", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next); // tail->next == head i.e first node
}

// Counting the elements
int countnodes(NODE tail)
{
    NODE temp = tail->next;
    int count = 0;
    while (temp != tail)
    {
        count++;
        temp = temp->next;
    }
    count++;
    return count;
}

int search(NODE tail, int element)
{
    int index = 0;
    NODE temp = tail->next;
    if (tail == NULL)
    {
        printf("Empty List");
        return -2;
    }

    do
    {
        if (temp->data == element)
        {
            printf("Found");
            return index;
        }
        temp = temp->next;
        index++;
    } while (temp != tail->next);
    printf("Not Found");
    return -1;
}