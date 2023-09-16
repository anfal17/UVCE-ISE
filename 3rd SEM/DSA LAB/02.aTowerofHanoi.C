/*2 a.Use recursive program to implement Tower of Hanoi:*/

#include<stdio.h>
#include<stdlib.h>

// Function to solve the Tower of Hanoi puzzle using recursion
// n: number of disks, source: source peg, dest: destination peg, temp: auxiliary peg
int towerOfHanoi(int n, char source, char dest, char temp)
{
    if (n > 0)
    {
        // Move n-1 disks from the source peg to the auxiliary peg using the destination peg as a temporary peg
        towerOfHanoi(n - 1, source, temp, dest);
        
        // Move the nth disk from the source peg to the destination peg
        printf("\nMove disk %d from %c to %c", n, source, dest);
        
        // Move the n-1 disks from the auxiliary peg to the destination peg using the source peg as a temporary peg
        towerOfHanoi(n - 1, temp, dest, source);
    }
    return 0;
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    
    // Call the towerOfHanoi function to solve the Tower of Hanoi puzzle
    towerOfHanoi(n, 'A', 'C', 'B'); // 'A' is the source peg, 'C' is the destination peg, and 'B' is the auxiliary peg
    
    return 0;
}

