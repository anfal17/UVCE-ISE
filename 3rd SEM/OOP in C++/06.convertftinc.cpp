/*Create two classes D1 and D2 which store the value of distances. D1 stores distances in meters and centimeters and D2 in feet and inches. Write a program to add objects of two classes D1 and D2 and the display the results in
feet and inches using friend function*/

#include <iostream>
using namespace std;

class D2;

class D1
{
private:
    int meters;
    int centimeters;

public:
    void get_data()
    {
        cout << "Enter distance in  meters and centimeters : ";
        cin >> meters >> centimeters;
    }
    friend void add(D1 obj1, D2 obj2);
};

class D2
{
private:
    int feet;
    int inches;

public:
    void get_data()
    {
        cout << "Enter distance in  feet and inches : ";
        cin >> feet >> inches;
    }
    friend void add(D1 obj1, D2 obj2);
};

void add(D1 obj1, D2 obj2)
{
    int d1_inches = obj1.meters * 39.37 + obj1.centimeters * 0.3937;
    int total_inches = d1_inches + obj2.feet * 12 + obj2.inches;

    int feet = total_inches / 12;
    int inches = total_inches % 12;

    cout << "Total distance: " << feet << " feet, " << inches << " inches " << endl;
}

int main() {
    D1 d1;
    D2 d2;
    d1.get_data();
    d2.get_data();

    add(d1, d2);
    return 0;
}

/*VIVA

1. **OOP Application:** This program uses classes to model different distance units.

2. **Encapsulation:** Encapsulation is achieved by bundling data and methods within classes.

3. **Friend Function:** The `add` function is a friend function that allows access to private class members for specific operations.

4. **Object Instantiation:** Objects `d1` and `d2` represent instances of the `D1` and `D2` classes.

5. **Inheritance:** Inheritance could be used to create a common base class for distance units.

6. **Polymorphism:** Polymorphism enables treating objects of different units as if they belong to a common base class.

7. **Improvements:** Potential improvements include data validation and a more generalized distance class hierarchy.

*/