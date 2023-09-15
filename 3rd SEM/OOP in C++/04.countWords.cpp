/*.Write a C++ Program to accept a line of text and count the number of words,characters and digits in it*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string line;
    int wordCount = 0, charCount = 0, digitCount = 0;
    cout << "Enter a line of text : ";
    getline(cin, line);

    for (int i = 0; i < line.length(); i++)
    {
        if (isalpha(line[i]))
        {
            charCount++;
        }
        else if (isdigit(line[i]))
        {
            digitCount++;
        }
        if (isspace(line[i]) && !isspace(line[i - 1])) /*current character is space and previous one is not space*/
        {
            wordCount++;
        }
    }
    // Checks if last word exists by checking if last char is not space
    if (!isspace(line[line.length() - 1]))
    {
        wordCount++;
    }
    cout << "Word count: " << wordCount << endl;
    cout << "Character count: " << charCount << endl;
    cout << "Digit count: " << digitCount << endl;
    return 0;
}

/*VIVA

Question 1: What is the purpose of this program?

Answer: The purpose of this program is to accept a line of text from the user and then count and display the following:

The number of words in the input line.
The number of alphabet characters (letters) in the input line.
The number of digit characters in the input line.
Question 2: How does the program count words in the input line?

Answer: The program counts words by examining each character in the input line. It counts a word whenever it encounters a space (' ') character that follows a non-space character. In other words, it increments the word count when it finds word boundaries.

Question 3: Why is the condition !isspace(line[i-1]) used when counting words?

Answer: The condition !isspace(line[i-1]) is used to ensure that consecutive spaces between words are not counted as multiple words. It checks that the previous character (at line[i-1]) was not a space before incrementing the word count. This helps accurately count the words in the input line.

Question 4: How does the program count alphabet characters?

Answer: The program counts alphabet characters by examining each character in the input line using the isalpha function from the <cctype> library. If a character is an alphabet character (a letter), it increments the character count.

Question 5: How does the program count digit characters?

Answer: The program counts digit characters by examining each character in the input line using the isdigit function from the <cctype> library. If a character is a digit, it increments the digit count.

Question 6: What happens if the last character in the input line is not a space?

Answer: If the last character in the input line is not a space, it indicates the presence of the last word in the line. The program increments the word count by 1 to count this last word.

Question 7: Can you explain the role of the getline function in this program?

Answer: The getline function is used to read a line of text from the user, including spaces. It stores the input text in the line variable, which is then processed to count words, characters, and digits.

*/