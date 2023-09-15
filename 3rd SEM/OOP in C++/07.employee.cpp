/*Given that an EMPLOYEE class contains the data members like E_Number, E_Name, Basic_salary, DA, HRA, Net_salary and the member functions like Read(), Calculate_Net_Sal(), and Display(). Write a C++ Program to read the data of N Employees and Compute the Net_Salary of each employee*/

#include <iostream>
using namespace std;

class employee
{
    int emp_number;
    char emp_name[20];
    float emp_basic;
    float emp_da;
    float emp_hra;
    float emp_net_sal;

public:
    void read();
    float calculate_net_salary();
    void display();
};

void employee::read()
{
    cout << "\nEnter employee number: ";
    cin >> emp_number;
    cout << "\nEnter employee name: ";
    cin >> emp_name;
    cout << "\nEnter employee basic: ";
    cin >> emp_basic;
    cout << "\nEnter employee DA: ";
    cin >> emp_da;
    cout << "\nEnter employee HRA: ";
    cin >> emp_hra;
}

float employee::calculate_net_salary()
{
    emp_net_sal = emp_basic + emp_da + emp_hra;
    return emp_net_sal;
}

void employee ::display()
{
    cout << "\n\n**** Details of Employee ****";
    cout << "\nEmployee Name : " << emp_name;
    cout << "\nEmployee number : " << emp_number;
    cout << "\nBasic salary : " << emp_basic;
    cout << "\nEmployee DA : " << emp_da;
    cout << "\nEmployee HRA : " << emp_hra;
    cout << "\nNet Salary : " << emp_net_sal;
    cout << "\n-------------------------------\n\n";
}

int main()
{
    int num_employees;
    int i;
    cout << "How many employees do you want to enter? ";
    cin >> num_employees;
    employee emp[num_employees];
    for (i = 0; i < num_employees; i++)
    {
        emp[i].read();
        emp[i].calculate_net_salary();
    }
    for (i = 0; i < num_employees; i++)
    {
        emp[i].display();
    }
    return 0;
}

/*VIVA

*/