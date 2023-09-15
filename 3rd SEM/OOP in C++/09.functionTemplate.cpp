/*Write a C++ program to find the following using Function Template
a) Successor value of any input of type integer, float, char and double.
b) Sum of all the elements of an array of integers or floats or doubles.
*/

#include <iostream>
using namespace std;

template <class T>
T successor(T x)
{
    return x++;
}

template <class X>
X sum(X arr[], int size)
{
    X total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total;
}

int main()
{
    // Finding the successor value of any input
    cout << "Successor of 5: " << successor(5) << endl;
    cout << "Successor of 5.5: " << successor(5.5) << endl;
    cout << "Successor of 'a': " << successor('a') << endl;

    // Finding the sum of all the elements of an array
    int int_arr[] = {1, 2, 3, 4, 5};
    float float_arr[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    double double_arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int int_arr_size = sizeof(int_arr) / sizeof(int);
    int float_arr_size = sizeof(float_arr) / sizeof(float);
    int double_arr_size = sizeof(double_arr) / sizeof(double);

    cout << "Sum of int array: " << sum(int_arr, int_arr_size) << endl;
    cout << "Sum of float array: " << sum(float_arr, float_arr_size) << endl;
    cout << "Sum of double array: " << sum(double_arr, double_arr_size)
         << endl;
    return 0;
}

/*VIVA
Question 2: What is a function template in C++?

Answer: A function template is a blueprint for creating generic functions that can work with different data types. It allows you to define a function without specifying the data type and lets the compiler determine the data type during compile time
*/