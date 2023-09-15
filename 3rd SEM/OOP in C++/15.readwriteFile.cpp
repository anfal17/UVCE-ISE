/*C++ program to read contents from one file and write it to another file.*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream in("file1.txt");
    ofstream f("file2.txt");

    while (!in.eof())
    {
        string text;
        getline(in, text);
        reverse(text.begin(), text.end());
        f << text << endl;
    }
    return 0;
    
}

/*VIVA

Question 1: What is the purpose of the ifstream and ofstream classes in C++?

Answer: ifstream is used for reading data from input files, and ofstream is used for writing data to output files. They are part of the C++ Standard Library's file input and output mechanism.

Question 2: How do you create an ifstream object for reading from a file?

Answer: To create an ifstream object for reading, you typically declare it and specify the name of the input file you want to open, like this:

ifstream inputFile("filename.txt");

Question 3: How do you create an ofstream object for writing to a file?

Answer: To create an ofstream object for writing, you declare it and specify the name of the output file you want to create or overwrite, like this:

ofstream outputFile("filename.txt");

Question 4: What happens if the specified input file does not exist when creating an ifstream object?

Answer: If the specified input file does not exist, the ifstream object will not be able to open the file, and subsequent file operations will fail. It's important to check if the file was successfully opened before attempting to read from it.

Question 5: How can you check if an ifstream or ofstream object has successfully opened a file?

Answer: You can check the validity of an ifstream or ofstream object by evaluating its is_open() member function. For example:


ifstream inputFile("filename.txt");
if (inputFile.is_open()) {
    // File is open and can be read.
} else {
    // Failed to open the file.
}

Question 6: What are some common operations you can perform with ifstream and ofstream objects?

Answer: Common operations include reading and writing data to/from files, checking for end-of-file (EOF) conditions, and seeking to specific positions in the file using functions like getline(), << (output operator), >> (input operator), and seekg()/seekp().

Question 7: How do you close an ifstream or ofstream object when you are done with it?

Answer: You can close an ifstream or ofstream object using the close() member function, like this:

inputFile.close();  // Closing an ifstream object
outputFile.close(); // Closing an ofstream object
Question 8: Can you have both an ifstream and an ofstream object for the same file in the same program?

Answer: Yes, you can have both an ifstream (for reading) and an ofstream (for writing) object for the same file in the same program. However, it's important to manage the file operations carefully to avoid conflicts or unexpected behavior.

These questions and answers cover the basics of using ifstream and ofstream objects in C++ file handling, which are essential for reading from and writing to files.

*/