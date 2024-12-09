#include<stdio.h>
#include<math.h>

// Function prototypes
void genhamcode();  // Function to generate Hamming code
void makeerror();   // Function to introduce an error in the Hamming code
void correcterror(); // Function to detect and correct the error in the Hamming code

int h[12];  // Array to store the Hamming code (1-based index)

int main() {
    int i, ch;

    // Input the message bits (positions 3, 5, 6, 7, 9, 10, 11)
    printf("\nEnter the message in bits\n");
    for (i = 1; i < 12; i++) {
        if (i == 3 || i == 5 || i == 6 || i == 7 || i == 9 || i == 10 || i == 11)
            scanf("%d", &h[i]);
    }

    // Display the original message bits
    printf("Original Message: ");
    for (i = 1; i < 12; i++)
        printf("%d", h[i]);
    printf("\n");

    // Generate the Hamming code
    genhamcode();

    // Ask the user if they want to introduce an error
    printf("\nDo you want to make an error (0 or 1)?\n");
    scanf("%d", &ch);
    if (ch) {
        makeerror();    // Introduce an error
        correcterror(); // Detect and correct the error
    } else {
        printf("\nNo error\n");
    }

    return 0;
}

// Function to generate the Hamming code with parity bits
void genhamcode() {
    int temp, i;

    // Calculate parity bits and insert them into the Hamming code
    temp = h[3] + h[5] + h[7] + h[9] + h[11];
    h[1] = (temp % 2 != 0) ? 1 : 0; // Parity bit at position 1

    temp = h[3] + h[6] + h[7] + h[10] + h[11];
    h[2] = (temp % 2 != 0) ? 1 : 0; // Parity bit at position 2

    temp = h[5] + h[6] + h[7];
    h[4] = (temp % 2 != 0) ? 1 : 0; // Parity bit at position 4

    temp = h[9] + h[10] + h[11];
    h[8] = (temp % 2 != 0) ? 1 : 0; // Parity bit at position 8

    // Display the generated Hamming code
    printf("\nTransmitted codeword is:\n");
    for (i = 1; i < 12; i++)
        printf("%d ", h[i]);
    printf("\n");
}

// Function to introduce an error at a specified position
void makeerror() {
    int pos, i;

    // Ask the user to specify the position to introduce an error
    printf("\nEnter the position you want to make an error\n");
    scanf("%d", &pos);
    h[pos] = (h[pos] == 1) ? 0 : 1; // Flip the bit at the specified position

    // Display the codeword with the introduced error
    printf("\nError occurred and the error codeword is\n");
    for (i = 1; i < 12; i++)
        printf("%d ", h[i]);
    printf("\n");
}

// Function to detect and correct the error
void correcterror() {
    int r1, r2, r4, r8, i, errpos;

    // Recalculate parity bits to determine the position of the error
    r1 = (h[1] + h[3] + h[5] + h[7] + h[9] + h[11]) % 2;
    r2 = (h[2] + h[3] + h[6] + h[7] + h[10] + h[11]) % 2;
    r4 = (h[4] + h[5] + h[6] + h[7]) % 2;
    r8 = (h[8] + h[9] + h[10] + h[11]) % 2;

    // Calculate the error position based on the parity bits
    errpos = r8 * 8 + r4 * 4 + r2 * 2 + r1 * 1;

    // Display the detected error position
    printf("\nError occurred in position %d\n", errpos);
    printf("\nCorrecting the error...\n");

    // Correct the error by flipping the bit at the error position
    h[errpos] = (h[errpos] == 1) ? 0 : 1;

    // Display the corrected codeword
    printf("\nCorrected codeword is:\n");
    for (i = 1; i < 12; i++)
        printf("%d ", h[i]);
    printf("\n");
}
