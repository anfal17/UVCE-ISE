/*9.Evaluate the given postfix expression using trees:*/

#include <stdio.h>
#include <conio.h>
#include <math.h>

// Define a structure for a node in the binary tree
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

typedef struct node *NODE;
NODE root = 0;

// Function prototypes
NODE create_tree(char postfix[]);
float eval(NODE root);

void main()
{
    char postfix[20];
    float result;
    // clrscr();
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);

    // Create a binary tree from the given postfix expression
    root = create_tree(postfix);

    // Evaluate the expression and print the result
    result = eval(root);
    printf("Result = %f\n", result);
    getch();
}

// Function to create a binary tree from a postfix expression
NODE create_tree(char postfix[])
{
    NODE temp, stack[20];
    int i = 0, j = 0;
    char symbol;

    for (i = 0; (symbol = postfix[i]) != 0; i++)
    {
        temp = (NODE)malloc(sizeof(struct node));
        temp->lchild = temp->rchild = 0;
        temp->data = symbol;

        if (isalnum(symbol)) // Operand (numeric or variable)
        {
            stack[j++] = temp;
        }
        else // Operator
        {
            temp->rchild = stack[--j];
            temp->lchild = stack[--j];
            stack[j++] = temp;
        }
    }

    return stack[--j];
}

// Function to evaluate the binary tree representing the postfix expression
float eval(NODE root)
{
    float num;
    switch (root->data)
    {
    case '+':
        return eval(root->lchild) + eval(root->rchild);
    case '-':
        return eval(root->lchild) - eval(root->rchild);
    case '/':
        return eval(root->lchild) / eval(root->rchild);
    case '*':
        return eval(root->lchild) * eval(root->rchild);
    case '^':
        return pow(eval(root->lchild), eval(root->rchild));
    default:
        if (isalpha(root->data)) // Variable (e.g., 'A', 'B')
        {
            printf("Enter the value of %c: ", root->data);
            scanf("%f", &num);
            return num;
        }
        else // Numeric operand
        {
            return (root->data - '0');
        }
    }
}
