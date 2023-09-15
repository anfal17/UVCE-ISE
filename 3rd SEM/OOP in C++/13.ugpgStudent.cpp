/*Write a C++ program to create a class called STUDENT with data members USN,Name and Age. Using inheritance, create the classes UGSTUDENT and PGSTUDENT having fields as Semester,Fees and Stipend. Enter the data for at least 5 students. Find the semester wise average age for all UG and PG students separately.*/

#include <iostream>
using namespace std;

class student
{
public:
    int reg, age;
    char name[20];
    void read_data();
};

class ugstudent : public student
{
public:
    int stipend, sem;
    float fees;
    void read_data();
};

class pgstudent : public student
{
public:
    int stipend, sem;
    float fees;
    void read_data();
};

void student::read_data()
{
    cout << "\n Enter name:";
    cin >> name;
    cout << "\n Enter Reg.no.";
    cin >> reg;
    cout << "\n Enter age:";
    cin >> age;
}

void ugstudent::read_data()
{
    student::read_data();
    cout << "\nEnter the sem:";
    cin >> sem;
    cout << "\nEnter the fees:";
    cin >> fees;
    cout << "\nEnter the stipend:";
    cin >> stipend;
}

void pgstudent::read_data()
{
    student::read_data();
    cout << "\nEnter the sem:";
    cin >> sem;
    cout << "\nEnter the fees:";
    cin >> fees;
    cout << "\nEnter the stipend:";
    cin >> stipend;
}

int main()
{
    ugstudent ug[20];
    pgstudent pg[20];
    int i, n, m;
    float average;
    cout << "\nEnter the no. of entries in the ugstudent class:";
    cin >> n;
    for (i = 1; i <= n; i++)
        ug[i].read_data();
    for (int sem = 1; sem <= 8; sem++)
    {
        float sum = 0;
        int found = 0, count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (ug[i].sem == sem)
            {
                sum = sum + ug[i].age;
                found = 1;
                count++;
            }
        }
        if (found == 1)
        {
            average = sum / count;
            cout << "\nAverage of age of sem " << sem << " is " << average;
        }
    }

    cout << "\nEnter the no. of entries in the pgstudent class:";
    cin >> n;
    for (i = 1; i <= n; i++)
        pg[i].read_data();
    for (int sem = 1; sem <= 8; sem++)
    {
        float sum = 0;
        int found = 0, count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (pg[i].sem == sem)
            {
                sum = sum + pg[i].age;
                found = 1;
                count++;
            }
        }
        if (found == 1)
        {
            average = sum / count;
            cout << "\nAverage of age of sem " << sem << " is " << average;
        }
    }
    return 0;
}

/*Viva

1. What is inheritance in C++?

Answer: Inheritance is a fundamental object-oriented programming concept that allows a class (called the derived or subclass) to inherit properties and behaviors from another class (called the base or superclass). It establishes an "is-a" relationship between classes.

3. What is a base class and a derived class?

Answer: In the context of inheritance, a base class (or superclass) is the class whose properties and behaviors are inherited by another class. A derived class (or subclass) is the class that inherits from the base class.

4. What is the purpose of the virtual keyword in the UGStudent and PGStudent classes?

Answer: The virtual keyword in the UGStudent and PGStudent classes is used to enable virtual inheritance. It ensures that the Student base class is shared only once among the derived classes, preventing ambiguity and reducing memory overhead in the case of multiple inheritance.

5. Explain the concept of member function overloading in C++.

Answer: Member function overloading is a feature in C++ that allows multiple functions with the same name but different parameters to exist within the same class. The appropriate function to execute is determined based on the number or type of arguments provided during the function call.

6. How are data members of a base class accessed in a derived class?

Answer: Data members of a base class can be accessed in a derived class using the scope resolution operator ::. For example, student::reg is used to access the reg member of the Student base class in a derived class.

7. What is the purpose of constructors in C++ classes?

Answer: Constructors are special member functions in C++ classes that are used to initialize objects of the class. They are automatically called when an object is created and help set the initial state of the object.

*/