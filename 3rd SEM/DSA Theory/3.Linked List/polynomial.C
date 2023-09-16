#include <stdio.h>
#include <stdlib.h>

struct node
{
    float coeff;
    int expo;
    struct node *link;
};

typedef struct node *NODE;

NODE create(NODE);
NODE insert(NODE, int, int);
NODE polyAdd(NODE, NODE);
void print(NODE);

int main()
{
    NODE poly1 = NULL;
    NODE poly2 = NULL;
    printf("Enter the first polynomial \n");
    poly1 = create(poly1);
    printf("Enter the second polynomial \n");
    poly2 = create(poly2);

    polyAdd(poly1, poly2);

    return 0;
}

NODE create(NODE head)
{
    int n;
    int i;
    float coeff;
    int expo;

    printf("Enter the number of terms : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the coefficient for term %d : ", i + 1);
        scanf("%f", &coeff);

        printf("Enter the Exponent for term %d : ", i + 1);
        scanf("%d", &expo);

        head = insert(head, coeff, expo);
    }
    return head;
}

NODE insert(NODE head, int co, int ex)
{
    NODE temp;
    NODE newP = (NODE)malloc(sizeof(struct node));
    newP->coeff = co;
    newP->expo = ex;
    newP->link = NULL;

    if (head == NULL || ex > head->expo)
    {
        newP->link = head;
        head = newP;
        return head;
    }

    temp = head;
    while (temp->link != NULL && ex < temp->link->expo)
    {
        temp = temp->link;
    }
    newP->link = temp->link;
    temp->link = newP;

    return temp;
}

NODE polyAdd(NODE poly1, NODE poly2)
{
    NODE ptr1 = poly1;
    NODE ptr2 = poly2;
    NODE poly3 = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo == ptr2->expo)
        {
            poly3 = insert(poly3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }

        else if (ptr1->expo > ptr2->expo)
        {
            poly3 = insert(poly3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        }

        else if (ptr1->expo < ptr2->expo)
        {
            poly3 = insert(poly3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while (ptr1 != NULL)
    {
        poly3 = insert(poly3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL)
    {
        poly3 = insert(poly3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->link;
    }
    printf("Added Polynomial is : ");

    print(poly3);

    return poly3;
}

void print(NODE head)
{
    if (head == NULL)
    {
        printf("No Polynomial!");
    }
    else
    {
        NODE temp = head;
        while (temp != NULL)
        {
            printf("(%.1fx^%d)", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}