/*2 b. Write a program to implement insertion sort:*/

#include <stdio.h>
#include <stdlib.h>

// Function prototype for insertion sort
void insertionSort(int a[], int n);

int main()
{
    int n, i, a[10];

    // Input the size of the array
    printf("Enter the size of an array : ");
    scanf("%d", &n);

    // Input the array elements
    printf("\nEnter the array elements :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Call the insertionSort function to sort the array
    insertionSort(a, n);

    // Display the sorted array
    printf("Array after sorting: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

void insertionSort(int a[], int n)
{
    int i, j, k;

    // Loop through each element in the array
    for (i = 1; i < n; i++)
    {
        k = a[i]; // Store the current element in a variable
        j = i - 1;

        // Move elements of a[0..i-1] that are greater than k to one position ahead of their current position
        while (j >= 0 && k < a[j])
        {
            a[j + 1] = a[j]; // Shift the element to the right
            j--;
        }

        a[j + 1] = k; // Place k in its correct position
    }
}
