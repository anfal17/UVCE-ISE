/*14. Compare the contents of two files. Write the difference in another file. */

#include <stdio.h>
#include <conio.h>

void main()
{
    FILE *fout1, *fout2, *fout3, *fin1, *fin2, *fin3;
    char data1[30], data2[30], ch1, ch2, ch3;
    clrscr();

    // Open file1.txt for writing
    fout1 = fopen("file1.txt", "w");

    // Check if the file opened successfully
    if (fout1 == NULL)
    {
        printf("Could not open file1");
        getch();
        exit(0);
    }

    // Open file2.txt for writing
    fout2 = fopen("file2.txt", "w");

    // Check if the file opened successfully
    if (fout2 == NULL)
    {
        printf("Could not open file2");
        getch();
        exit(0);
    }

    // Prompt the user to enter content for file1
    printf("Enter content for file1:\n");
    gets(data1);

    // Prompt the user to enter content for file2
    printf("Enter content for file2:\n");
    gets(data2);

    // Write data1 to file1.txt and data2 to file2.txt
    fprintf(fout1, "%s", data1);
    fprintf(fout2, "%s", data2);

    // Close file1.txt and file2.txt
    fclose(fout1);
    fclose(fout2);

    // Open file1.txt for reading
    fin1 = fopen("file1.txt", "r");

    // Check if the file opened successfully
    if (fin1 == NULL)
    {
        printf("Could not read from file 1");
        getch();
        exit(0);
    }

    // Open file2.txt for reading
    fin2 = fopen("file2.txt", "r");

    // Check if the file opened successfully
    if (fin2 == NULL)
    {
        printf("Could not read from file 2");
        getch();
        exit(0);
    }

    // Open file3.txt for writing the differences
    fout3 = fopen("file3.txt", "w");

    // Check if the file opened successfully
    if (fout3 == NULL)
    {
        printf("Could not open file 3");
        getch();
        exit(0);
    }

    // Initialize characters ch1, ch2, and ch3
    ch1 = getc(fin1);
    ch2 = getc(fin2);

    // Compare characters in file1.txt and file2.txt
    while (ch1 != EOF && ch2 != EOF)
    {
        if (ch1 != ch2)
        {
            // If characters are different, write ch2 to file3.txt
            fputc(ch2, fout3);
        }

        // Read the next characters from file1.txt and file2.txt
        ch1 = getc(fin1);
        ch2 = getc(fin2);
    }

    // Close file1.txt, file2.txt, and file3.txt
    fclose(fin1);
    fclose(fin2);
    fclose(fout3);

    // Open file3.txt for reading the differences
    fin3 = fopen("file3.txt", "r");

    // Check if the file opened successfully
    if (fin3 == NULL)
    {
        printf("Could not read from file 3");
        getch();
        exit(0);
    }

    // Read and display the differences from file3.txt
    printf("Differences between file1 and file2 are:\n");
    while ((ch3 = getc(fin3)) != EOF)
    {
        printf("%c", ch3);
    }

    // Close file3.txt
    fclose(fin3);

    getch();
}


/*
Explanation:

The code begins by declaring file pointers for three input files (fin1, fin2, fin3) and three output files (fout1, fout2, fout3), along with character arrays to store data.

It clears the screen using clrscr().

The program opens file1.txt and file2.txt for writing, checking if the files opened successfully. If not, it exits with an error message.

The user is prompted to enter content for both file1.txt and file2.txt. The input is stored in data1 and data2, respectively.

Using fprintf, it writes the contents of data1 to file1.txt and the contents of data2 to file2.txt.

The program then closes both file1.txt and file2.txt.

It reopens file1.txt and file2.txt for reading and checks if they opened successfully. If not, it exits with an error message.

The program opens file3.txt for writing, which will contain the differences between file1.txt and file2.txt. It checks if the file opened successfully.

Characters ch1 and ch2 are initialized to read from file1.txt and file2.txt, respectively.

The program compares the characters read from file1.txt and file2.txt in a loop. If the characters are different, it writes ch2 (from file2.txt) to file3.txt.

The program continues reading characters until the end of either file1.txt or file2.txt.

It closes file1.txt, file2.txt, and file3.txt.

file3.txt is reopened for reading, and it checks if it opened successfully. If not, it exits with an error message.

Finally, the program reads and displays the differences between file1.txt and file2.txt from file3.txt on the screen.

explanation credits -- chatgpt

*/