/*13. Write all the members of an array of structures to a file using fwrite(). Read
the array from the file and display it on the screen. */

#include <stdio.h>
#include <conio.h>

// Define a structure to represent a student
struct student
{
    int regno;
    char name[20];
};

void main()
{
    // Declare an array of student structures
    struct student stud[20], temp;

    // Declare file pointers for input and output
    FILE *fout, *fin;

    int i, n;
    clrscr();

    // Open a file for writing (creating) student records
    fout = fopen("student.txt", "w");

    // Check if the file opened successfully
    if (fout == NULL)
    {
        printf("Error, could not open the file for writing....");
        getch();
        exit(0);
    }

    // Prompt the user to enter the number of students
    printf("Enter the number of students:");
    scanf("%d", &n);

    // Loop to input student information
    for (i = 0; i < n; i++)
    {
        clrscr();
        printf("For student %d:\n", i + 1);
        printf("Name:");
        scanf("%s", stud[i].name);
        printf("Register no:");
        scanf("%d", &stud[i].regno);
    }

    // Write the array of student structures to the file
    fwrite(stud, sizeof(struct student), n, fout);

    // Close the output file
    fclose(fout);

    // Open the file for reading student records
    fin = fopen("student.txt", "r");

    // Check if the file opened successfully
    if (fin == NULL)
    {
        printf("Error, could not open the file for reading....");
        getch();
        exit(0);
    }

    clrscr();

    // Display the data read from the file
    printf("\nData read from the file is as follows:\n");

    // Read and display each student record
    while (fread(&temp, sizeof(struct student), 1, fin))
    {
        printf("Name:%s\n", temp.name);
        printf("Reg No:%d\n\n", temp.regno);
        getch();
    }

    // Close the input file
    fclose(fin);
}


/*
Explanation:

The code begins by defining a structure student to represent student records. It contains two members: regno for the registration number (an integer) and name for the student's name (a character array).

An array of student structures, stud, is declared to store student records. Another temporary student structure, temp, is declared for reading records from the file.

File pointers, fout and fin, are declared for output and input files, respectively.

The program clears the screen using clrscr() and then opens a file named "student.txt" for writing ("w" mode). It checks if the file opened successfully and exits with an error message if it didn't.

The user is prompted to enter the number of students (n) whose records they want to create.

A loop is used to input student information for each student, including their name and registration number. The data is stored in the stud array.

The fwrite function is used to write the entire stud array to the file. It writes n records of sizeof(struct student) bytes each.

The output file is closed using fclose(fout).

The program reopens the file, this time for reading ("r" mode), and checks if it opened successfully. If not, it exits with an error message.

The program clears the screen again and displays a message to indicate that it is displaying data read from the file.

A while loop reads each student record from the file using fread and stores it in the temp structure. It continues reading until it reaches the end of the file.

Inside the loop, the program displays the student's name and registration number, and getch() is used to pause and wait for user input before displaying the next record.

After reading all records, the input file is closed using fclose(fin).

This program effectively writes student records to a file using fwrite() and then reads and displays them on the screen. It demonstrates basic file I/O operations and the use of structures to store and manage data.




explanation credits -- chatgpt
*/