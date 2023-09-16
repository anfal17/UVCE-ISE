/*12. Implement Hashing using open addressing */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int a[100], a1[100], i, j, result, n, cnt = 0;
    // clrscr();

    // Prompt the user to enter the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Prompt the user to enter the elements
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Initialize the hash table (a1) with -1 values
    for (i = 0; i < 10; i++)
        a1[i] = -1;

    // Iterate through the input elements
    for (i = 0; i < n; i++)
    {
        // Calculate the initial hash value by taking the remainder when dividing by 10
        result = a[i] % 10;

        // If the slot is empty, insert the element there
        if (a1[result] == -1)
        {
            a1[result] = a[i];
            printf("Location: a1[%d], Value: %d\n", result, a1[result]);
        }
        else
        {
            j = result + 1;

            // If the slot is occupied, use open addressing to find the next available slot
            while (1)
            {
                // If an empty slot is found, insert the element
                if (a1[j] == -1)
                {
                    a1[j] = a[i];
                    printf("Location: a1[%d], Value: %d\n", j, a1[j]);
                    break;
                }

                // If we reach the end of the array, wrap around to the beginning
                if (j > n - 1)
                    j = 0;

                // If we've checked all slots and couldn't find an empty one, break
                if (cnt == n)
                    break;

                // Move to the next slot
                cnt++;
                j++;
            }
        }

        // Reset the result and count for the next element
        result = 0;
        cnt = 0;
    }

    // Print the resulting hash table using open addressing
    printf("Hash table using open addressing mode:\n");
    for (i = 0; i < 10; i++)
    {
        if (a1[i] != -1)
            printf("%d ", a1[i]);
    }

    getch();
}

/*
Explanation:

The code begins by declaring arrays a and a1, as well as integer variables i, j, result, n, and cnt to manage elements and their calculations.

The user is prompted to enter the number of elements they want to store in the hash table.

The user is prompted to enter the elements one by one, which are stored in array a.

Array a1 is initialized with -1 values, indicating empty slots in the hash table.

The code iterates through the input elements in a. For each element, it calculates the initial hash value by taking the remainder when dividing by 10 (result = a[i] % 10).

If the slot at the calculated location in a1 is empty (a1[result] == -1), the element is inserted there, and the location and value are printed.

If the slot is occupied, open addressing is used to find the next available slot. The code checks the next slot and continues checking until an empty slot is found.

To handle edge cases where the search for an empty slot wraps around the array or when all slots have been checked (j > n - 1 or cnt == n), appropriate actions are taken.

The result and count are reset for the next element.

Finally, the resulting hash table using open addressing is printed, displaying the inserted values.

Hashing Using Open Addressing:

Open addressing is a collision resolution technique used in hash tables. When a collision occurs (i.e., when two elements map to the same hash value), open addressing finds the next available slot in the table to store the colliding element. This can involve linear probing (checking slots sequentially) or other methods to find an empty slot. Open addressing allows efficient handling of collisions and ensures that all elements can be stored in the table.
*/