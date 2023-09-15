/*Write a C++ program to overload the function Search() to search an integer key value and a key value of type double*/

#include <iostream>
using namespace std;

int search(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int search(double arr[], int n, double key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int intArr[] = {10, 20, 30, 40, 50};
    double doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    // Searching for an integer key value
    int intIndex = search(intArr, 5, 30);
    if (intIndex != -1)
    {
        cout << "Integer key value found at index " << intIndex << endl;
    }
    else
    {
        cout << "Integer key value not found" << endl;
    }
    // Searching for a key value of type double
    int doubleIndex = search(doubleArr, 5, 3.3);
    if (doubleIndex != -1)
    {
        cout << "Double key value found at index " << doubleIndex << endl;
    }
    else
    {
        cout << "Double key value not found" << endl;
    }
    return 0;
}

/*VIVA

Question 2: What is function overloading, and how is it implemented in this program?

Answer: Function overloading is a feature in C++ that allows defining multiple functions with the same name but different parameter lists. In this program, function overloading is implemented by having two search functions with different parameter types (integers and doubles).

Question 4: Why is it necessary to have two different search functions for integers and doubles?

Answer: It is necessary to have two different search functions because C++ distinguishes function overloads based on the number and type of their parameters. Since integers and doubles are distinct data types, we need separate functions to handle each type.
*/