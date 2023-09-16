/*A self-referential structure, also known as a recursive structure, is a data structure in which one or more of its members are pointers to objects of the same type. In other words, it's a structure that refers to itself or contains elements of its own type as members

struct Node {
    int data;
    struct Node* next; // This member is a pointer to another Node
};
*/

#include <stdio.h>
#include <stdlib.h>

// Define the self-referential structure for a Person
struct Person
{
    char name[50];
    int age;
    struct Person *friends; // Pointer to another Person
};

int main()
{
    // Create two Person structures
    struct Person person1, person2;

    // Fill in information for person1
    printf("Enter name for person1: ");
    scanf("%s", person1.name);
    printf("Enter age for person1: ");
    scanf("%d", &person1.age);

    // Fill in information for person2
    printf("Enter name for person2: ");
    scanf("%s", person2.name);
    printf("Enter age for person2: ");
    scanf("%d", &person2.age);

    // Set person1's friends to person2
    person1.friends = &person2;

    // Display information about person1 and their friends
    printf("\nPerson1:\nName: %s\nAge: %d\n", person1.name, person1.age);
    printf("Person1's Friend:\nName: %s\nAge: %d\n", person1.friends->name, person1.friends->age);

    return 0;
}
