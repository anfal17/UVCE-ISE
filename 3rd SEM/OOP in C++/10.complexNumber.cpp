/*Write a C++ Program to create a class as COMPLEX and implement the following by overloading the function ADD() which returns the Complex numbers
a) ADD(C1, C2); C1 is an integer ; C2 is a Complex number.
b) ADD(C1, C2); C1 and C2 are Complex numbers*/

#include <iostream>
using namespace std;

class complex
{
private:
    float real;
    float imag;

public:
    complex()
    {
        real = 0;
        imag = 0;
    }

    complex(int r)
    {
        real = r;
        imag = 0;
    }
    complex(float r, float i)
    {
        real = r;
        imag = i;
    }

    complex ADD(complex c)
    {
        complex res;
        res.real = real + c.real;
        res.imag = imag + c.imag;
        return res;
    }

    complex ADD(int r)
    {
        complex res;
        res.real = real + r;
        res.imag = imag;
        return res;
    }

    void display()
    {

        if (imag < 0)
        {
            cout << real << " -i " << abs(imag) << endl;
        }
        else
        {
            cout << real << " +i " << imag << endl;
        }
    }
};

int main()
{
    complex C1(4, 5);
    complex C2(3, -2);
    complex C3;
    cout << "C1 = ";
    C1.display();
    cout << "C2 = ";
    C2.display();
    C3 = C1.ADD(C2); // Adding two Complex numbers
    cout << "C1 + C2 = ";
    C3.display();
    C3 = C1.ADD(2); // Adding an integer and a Complex number
    cout << "C1 + 2 = ";
    C3.display();
    return 0;
}

/*
What are constructors?"

Answer: Constructors are special member functions in object-oriented programming (OOP) that have the same name as the class they belong to. They are automatically invoked when an object of the class is created. The primary purpose of constructors is to initialize the member variables of an object, ensuring it starts in a valid and well-defined state. Constructors can be overloaded, allowing a class to have multiple constructors with different parameter lists to accommodate various object initialization scenarios.
*/