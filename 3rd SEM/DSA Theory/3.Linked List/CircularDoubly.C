#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
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
    tail = insert_after_pos(tail, 76, 4);
    printf("Before deletion ");
    print(tail);

    tail = delete_at_first(tail);
    // tail = delete_at_end(tail);
    printf("\nAfter deletion\t ");
    print(tail);
    tail = delete_at_pos(tail, 3);
    printf("\nAfter deletion\t ");
    print(tail);

    return 0;
}

NODE addToEmpty(int data)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = temp;
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
    NODE temp = tail->next;

    newP->prev = tail;
    newP->next = temp;
    tail->next = newP;
    temp->prev = newP;
    return tail;
}

NODE insert_at_end(NODE tail, int data)
{
    NODE newP = addToEmpty(data);
    if (tail == NULL)
    {
        return newP;
    }
    NODE temp = tail->next; // first node
    newP->next = temp;
    newP->prev = tail;
    tail->next = newP;
    temp->prev = newP;
    tail = newP;
    return tail;
}

NODE insert_after_pos(NODE tail, int data, int pos)
{
    NODE newP = addToEmpty(data);
    if (tail == NULL)
    {
        return newP;
    }
    NODE ptr = tail->next;
    while (pos > 1)
    {
        ptr = ptr->next;
        pos--;
    }
    newP->next = ptr->next;
    newP->prev = ptr;
    ptr->next->prev = newP;
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
    ptr->next->prev = tail;
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

    NODE ptr = tail->prev;
    ptr->next = tail->next;
    tail->next->prev = ptr;
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
    if (tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }

    NODE ptr = tail->next;
    while (pos > 1)
    {
        ptr = ptr->next;
        pos--;
    }
    if(ptr == tail->next)
    {
        tail = delete_at_first(tail);
        return tail;
    }
    if (ptr == tail)
    {
        tail = delete_at_end(tail);
        return tail;
    }
    
    NODE ptr2 = ptr->prev;
    ptr2->next = ptr->next;
    ptr->next->prev = ptr2; 
    // if ptr2 == tail
    if (ptr2 == tail)
    {
        tail = ptr;
    }
    free(ptr);
    ptr = NULL;
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