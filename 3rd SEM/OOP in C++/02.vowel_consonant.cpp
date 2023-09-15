/*Write a C++ Program to accept an alphabet and check whether it is a vowel or
a consonant. If it is a vowel return its predecessor else its successor. Use
call-by-reference with reference arguments*/

#include <iostream>
using namespace std;

void alphab(char &data)
{
    char result;
    data = tolower(data);
    if (isalpha(data))
    {
        if (data == 'a' || data == 'e' || data == 'i' || data == 'o' || data == 'u')
        {
            cout << data << " is vowel "
                 << " its predecessor is " << --data << endl;
        }
        else
        {
            cout << data << " is consonant"
                 << " its successor is " << ++data << endl;
        }
    }
}

int main()
{
    char param, data;
    cout << "Enter the alphabet : ";
    cin >> param;
    alphab(param);
    return 0;
}

/*Viva
Question 1: What is the purpose of using using namespace std; in this program?

Answer: using namespace std; is used to include the standard C++ library's std namespace. It allows us to use standard C++ functions and objects (like cin, cout, and endl) without prefixing them with std::.

Question 2: Why is char used as the parameter type in the alphab function?

Answer: char is used as the parameter type because we are passing a single character (an alphabet) to the function. This allows us to modify the character directly within the function.

Question 3: What is the purpose of tolower(data) in the alphab function?

Answer: tolower(data) is used to convert the input character to its lowercase form. This ensures that the program works correctly regardless of whether the user enters an uppercase or lowercase alphabet.

Question 4: Explain the concept of call-by-reference in C++.

Answer: Call-by-reference is a mechanism in C++ where a function receives a reference to a variable as its argument. Any changes made to the parameter inside the function directly affect the original variable in the calling code. In this program, char &data in the alphab function's parameter list is an example of call-by-reference.

Question 5: What does the isalpha(data) check inside the alphab function do?

Answer: isalpha(data) is a standard C++ library function that checks if the character data is an alphabetic character (a letter). It returns true if it's an alphabet character and false otherwise. This check ensures that we only perform the vowel or consonant transformation on valid alphabet characters.

Question 6: How does the program differentiate between vowels and consonants?

Answer: The program differentiates between vowels and consonants by checking if the character entered by the user (data) matches any of the vowels ('a', 'e', 'i', 'o', 'u'). If it's a vowel, it increments the character by one; otherwise, it decrements it by one.

Question 7: Why is static_cast<char> used when incrementing or decrementing data?

Answer: static_cast<char> is used to explicitly cast the result of the increment or decrement operation to the char type. This is necessary because characters are treated as integers in C++ when performing arithmetic operations, and the cast ensures that the result remains a character.
*/