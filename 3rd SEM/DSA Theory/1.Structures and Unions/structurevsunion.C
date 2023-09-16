#include <stdio.h>
#include <string.h>

// Define a structure
struct Student
{
    char name[50];
    int rollNumber;
};

// Define a union
union Color
{
    char rgb[3];
    int hex;
};

int main()
{
    // Difference 1: Memory Allocation
    // Structures allocate memory for all members separately,
    // while unions share the same memory location for all members.

    struct Student student;
    union Color color;

    printf("Size of struct Student: %lu bytes\n", sizeof(student));
    printf("Size of union Color: %lu bytes\n\n", sizeof(color));

    // Difference 2: Memory Consumption
    // Structures consume memory for all members simultaneously,
    // while unions consume memory only for the largest member.

    struct
    {
        char a;
        int b;
        char c;
    } structExample;

    union
    {
        char a;
        int b;
    } unionExample;

    printf("Size of structExample: %lu bytes\n", sizeof(structExample));
    printf("Size of unionExample: %lu bytes\n\n", sizeof(unionExample));

    // Difference 3: Access to Members
    // In structures, you can access each member individually,
    // while in unions, you can access only one member at a time.

    struct Student student1;
    student1.rollNumber = 101;

    union Color color1;
    color1.hex = 0xFFAABB;

    printf("Student rollNumber: %d\n", student1.rollNumber);
    printf("Color hex: %X\n\n", color1.hex);

    // Difference 4: Member Modification
    // In structures, modifying one member doesn't affect others,
    // while in unions, modifying one member may affect others,
    // as they share the same memory location.

    struct Student student2;
    student2.rollNumber = 202;
    printf("Student rollNumber: %d\n", student2.rollNumber);

    union Color color2;
    color2.hex = 0x112233;
    color2.rgb[0] = 'R'; // Modifying one member affects others
    printf("Color hex: %X\n", color2.hex);

    // Difference 5: Storage of Values
    // Structures store values of all members independently,
    // while unions store the value of only one member at a time.

    struct Student student3;
    student3.rollNumber = 303;
    strcpy(student3.name, "Alice");

    union Color color3;
    color3.rgb[0] = 'G';
    color3.rgb[1] = 'B';
    color3.rgb[2] = 'R';

    printf("Student name: %s\n", student3.name);
    printf("Color rgb: %c%c%c\n", color3.rgb[0], color3.rgb[1], color3.rgb[2]);

    return 0;
}
