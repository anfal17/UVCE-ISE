/*
   3. Write a program to convert a given infix expression to prefix:
*/

#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

// Function prototypes
void infixToPostfix();
void push(char);
char pop();
int isEmpty();
void print();
int precedence(char);
int isSpace(char);

int main()
{
    printf("Enter the infix expression : ");
    gets(infix);

    infixToPostfix(); // Convert infix expression to postfix
    print();          // Display the equivalent postfix expression
    return 0;
}

void infixToPostfix()
{
    int i, j = 0;
    char next;
    char symbol;
    for (i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];

        // Check if the symbol is not a whitespace
        if (!isSpace(symbol))
        {
            switch (symbol)
            {
            case '(':
                push(symbol); // Push '(' onto the stack
                break;
            case ')':
                // Pop and append operators until '(' is encountered
                while ((next = pop()) != '(')
                {
                    postfix[j++] = next; // Append popped operators to postfix
                }
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                // Pop operators with higher or equal precedence and then push the current operator
                while (!isEmpty() && precedence(stack[top]) >= precedence(symbol))
                {
                    postfix[j++] = pop(); // Append popped operators to postfix
                }
                push(symbol); // Push the current operator onto the stack
                break;

            default: // If the symbol is an operand, append it to the postfix expression
                postfix[j++] = symbol;
                break;
            }
        }
    }
    // Pop and append any remaining operators in the stack
    while (!isEmpty())
    {
        postfix[j++] = pop(); // Append popped operators to postfix
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int isSpace(char c)
{
    // Check if the symbol is a blank space or a tab
    if (c == ' ' || c == '\t')
        return 1;
    else
        return 0;
}

int precedence(char symbol)
{
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;

    default:
        return 0; // Default precedence for other characters
    }
}

void print()
{
    int i = 0;
    printf("The equivalent postfix expression is : ");
    while (postfix[i])
    {
        printf("%c", postfix[i++]); // Display the postfix expression
    }
    printf("\n");
}

void push(char c)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n"); // Stack is full
        return;
    }
    top++;
    stack[top] = c; // Push character onto the stack
}

char pop()
{
    char c;
    if (top == -1)
    {
        printf("Stack Underflow\n"); // Stack is empty
        exit(1);
    }
    c = stack[top];
    top = top - 1;
    return c; // Pop and return the character from the stack
}

int isEmpty()
{
    if (top == -1)
        return 1; // Stack is empty
    else
        return 0; // Stack is not empty
}
