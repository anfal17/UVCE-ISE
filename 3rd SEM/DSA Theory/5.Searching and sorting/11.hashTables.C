/*11. Implement Hash Tables */

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

void main()
{
    int a[100], a1[100], a2[100], i, result, n;
    // clrscr();

    // Prompt the user to enter the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Prompt the user to enter the elements
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Initialize two arrays to store hash table values
    for (i = 0; i < n; i++)
    {
        // Calculate the hash value by taking the remainder when dividing by 10
        result = a[i] % 10;

        // Store the original value in a2
        a2[i] = a[i];

        // Store the original value in a1 at the calculated location
        a1[result] = a[i];

        // Print the location and value stored in a1
        printf("Location: a1[%d], value: %d\n", result, a1[result]);
    }

    // Print the resulting hash table (a2)
    printf("Hash table:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a2[i]);

    getch();
}

/*Hash Tables:

A hash table is a data structure that allows you to store and retrieve values based on a key or hash value. It's an efficient way to store and look up data, especially when you have a large dataset. Hash tables consist of an array and a hash function. The hash function takes an input (key) and produces a fixed-size integer, which is used as an index to store and retrieve values in the array. Hash tables offer constant-time average complexity for search, insertion, and deletion operations when the hash function distributes data evenly.

In this code, a basic hash table is implemented where the hash value is calculated as the remainder when dividing elements by 10. The original values and their hashed locations are stored and printed to demonstrate a simple example of a hash table.*/