/*
Write a C++ program to create a base class Student, from this inherit a new class called Exams, containing Marks1, Marks2 and Marks3 as its data Members. Also create another class called Sports having Sports_grades its data member. Now, create yet another class but a derived class of Exams and Sports classes and call it as Awards. Use appropriate member functions in all classes. You can use the Regno, Name, Semester and Branch as the members of the base class.*/

#include <iostream>
using namespace std;

class Student
{
public:
    int Regno;
    char Name[20];
    int Semester;
    char Branch[20];
    void GetData()
    {
        cout << "Enter Regno: ";
        cin >> Regno;
        cout << "Enter Name: ";
        cin >> Name;
        cout << "Enter Semester: ";
        cin >> Semester;
        cout << "Enter Branch: ";
        cin >> Branch;
    }
};

class Exams : public virtual Student
{
public:
    int Marks1;
    int Marks2;
    int Marks3;
    void GetMarks()
    {
        cout << "Enter Marks1: ";
        cin >> Marks1;
        cout << "Enter Marks2: ";
        cin >> Marks2;
        cout << "Enter Marks3: ";
        cin >> Marks3;
    }
};

class Sports : public virtual Student
{
public:
    char Sports_grade;
    void GetSports()
    {
        cout << "Enter Sports Grade: ";
        cin >> Sports_grade;
    }
};

class Awards : public Exams, public Sports
{
public:
    void Display()
    {
        cout << "Name: " << Student::Name << endl;
        cout << "Regno: " << Student::Regno << endl;
        cout << "Branch: " << Student::Branch << endl;
        cout << "Exams Semester: " << Exams::Semester << endl;
        cout << "Marks1: " << Marks1 << endl;
        cout << "Marks2: " << Marks2 << endl;
        cout << "Marks3: " << Marks3 << endl;
        cout << "Sports Semester: " << Sports::Semester << endl;
        cout << "Sports Grade: " << Sports_grade << endl;
    }
};

int main()
{
    Awards a1;
    a1.GetData();
    a1.GetMarks();
    a1.GetSports();
    a1.Display();
    return 0;
}

/*VIVA
Question 1: What is the purpose of the virtual keyword in C++ inheritance, as used in this program?

Answer: The virtual keyword is used for virtual inheritance. In this program, it's used to enable the Awards class to inherit from both Exams and Sports while avoiding the "diamond problem" in multiple inheritance. It ensures that the Student base class is shared only once among the derived classes.

Question 2: What is the "diamond problem" in C++ multiple inheritance, and how does virtual inheritance solve it?

Answer: The "diamond problem" occurs when a class inherits from two classes that share a common base class. This can lead to ambiguity in member access. Virtual inheritance solves this problem by ensuring that the common base class is shared only once among the derived classes, eliminating ambiguity.

Question 3: Explain the purpose of the GetData(), GetMarks(), and GetSports() member functions in this program.

Answer: These member functions are used to input data for the Awards object. GetData() inputs common student information, GetMarks() inputs exam marks, and GetSports() inputs sports grades.

Question 4: In the Display() function of the Awards class, how are data members from both Exams and Sports accessed?

Answer: Data members from both base classes are accessed using the scope resolution operator ::. For example, Exams::Semester and Sports::Semester are used to access the Semester data member from the Exams and Sports base classes, respectively.

Question 5: Can you explain the sequence of constructor calls when an Awards object is created?

Answer: When an Awards object is created, the constructor of the most base class (Student) is called first. Then, the constructors of Exams and Sports are called in an unspecified order. Finally, the constructor of the Awards class is called.

Question 6: What is the significance of using the virtual keyword when inheriting from Student in the Exams and Sports classes?

Answer: The virtual keyword in inheritance ensures that the Student base class is shared only once among the derived classes. It avoids multiple copies of Student objects in the hierarchy, preventing ambiguity and reducing memory overhead.

Question 7: Why is multiple inheritance used in this program, and what advantages does it provide?

Answer: Multiple inheritance is used to combine characteristics from different base classes into a single derived class (Awards). It allows the Awards class to inherit properties related to both exams and sports. This provides flexibility and code reuse.
*/
