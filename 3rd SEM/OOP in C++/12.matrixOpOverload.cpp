/*
Write a C++ program to create a class called MATRIX using a two dimensional array of integers.Implement the following operations by overloading the operator == which checks the compatibility of the two matrices to be added and subtracted. Perform the addition and subtraction by
overloading the operators + and - respectively. Display the results by overloading operator <<.
if(m1==m2)
{
}
else
 Display error
Where m1, m2, m3 and m4 are MATRIX objects
*/

#include <iostream>
using namespace std;

class matrix
{
private:
    long m[5][5];
    int row, col;

public:
    void getdata();
    int operator==(matrix);
    matrix operator+(matrix);
    matrix operator-(matrix);
    friend ostream &operator<<(ostream &, matrix &);
};

int matrix::operator==(matrix cm)
{
    if (row == cm.row && col == cm.col)
    {
        return 1;
    }
    return 0;
}

void matrix::getdata()
{
    cout << "enter the number of rows\n";
    cin >> row;
    cout << "enter the number of columns\n";
    cin >> col;
    cout << "enter the elements of the matrix\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> m[i][j];
        }
    }
}

matrix matrix::operator+(matrix am)
{
    matrix temp;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp.m[i][j] = m[i][j] + am.m[i][j];
        }
        temp.row = row;
        temp.col = col;
    }
    return temp;
}

matrix matrix::operator-(matrix sm)
{
    matrix temp;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            temp.m[i][j] = m[i][j] - sm.m[i][j];
        }
        temp.row = row;
        temp.col = col;
    }
    return temp;
}

ostream &operator<<(ostream &fout, matrix &d)
{
    for (int i = 0; i < d.col; i++)
    {
        for (int j = 0; j < d.col; j++)
        {
            fout << d.m[i][j];
            cout << " ";
        }
        cout << endl;
    }
    return fout;
}

int main()
{
    matrix m1, m2, m3, m4;

    m1.getdata();
    m2.getdata();
    if (m1 == m2)
    {
        m3 = m1 + m2;
        m4 = m1 - m2;
        cout << "Addition of matrices\n";
        cout << "the result is\n";
        cout << m3;
        cout << "subtraction of matrices\n";
        cout << "The result is \n";
        cout << m4;
    }
    else
    {
        cout << "order of the input matrices is not identical\n";
    }
    return 0;
}

/*VIVA

Viva Questions:

What is the purpose of overloading operators in C++?

Operator overloading allows you to define how operators behave when used with objects of user-defined classes. It provides a way to make your classes work with operators like +, -, ==, etc.
How is the operator== function used in this program, and what does it check?

The operator== function is used to check the compatibility of two matrices for addition and subtraction. It checks if the number of rows and columns of two matrices are the same.
How are the addition and subtraction operations implemented for matrices in this program?

The addition and subtraction operations are implemented using the operator+ and operator- member functions, respectively. They iterate through the elements of the matrices and perform element-wise addition and subtraction.
How does operator overloading improve code readability and usability?

Operator overloading allows you to write code that closely resembles mathematical expressions, making it more intuitive and readable. It improves code usability by allowing custom types to work with standard operators.
What happens if two matrices are not compatible for addition or subtraction?

If two matrices are not compatible (i.e., their dimensions do not match), the program outputs an error message indicating that the order of the input matrices is not identical.
Explain the purpose of the friend keyword in the operator<< overload function.

The friend keyword allows the operator<< function to access the private data members of the matrix class, enabling it to display the matrix's contents.*/