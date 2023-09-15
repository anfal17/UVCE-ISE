/*Write a C++ Program to call a C function using an extern “C” linkage directive.
Use compound statement linkage directive for #include<math.h>*/

#include<iostream>
#include<math.h>
using namespace std;

extern "C" {
    double my_sqrt(double x) {
        return sqrt(x);
    }
}

int main() {
    double x = 100;
    double y = my_sqrt(x);
    cout<<"Square root of "<<x<<" is "<< y << endl;
    return 0;
}

/*
Question 1: What is the purpose of the extern "C" linkage directive in this program?

Answer: The extern "C" linkage directive is used to specify that the my_sqrt function should have C linkage rather than C++ linkage. This is important when you want to interface with C functions in a C++ program because C and C++ have different name mangling conventions. Using extern "C" ensures that the function's name remains unchanged and compatible with C function names.

Question 2: How does the my_sqrt function work?

Answer: The my_sqrt function takes a double as its argument and returns the square root of that number using the sqrt function from the C standard library. It is declared with extern "C" to ensure C linkage.

Question 3: Why is it necessary to include the <cmath> header in this program?

Answer: The <cmath> header is included because it provides the declaration for the sqrt function, which is used in the my_sqrt function to calculate the square root of a number.


Question 5: How does the program calculate and display the square root of 100?

Answer: The program calculates the square root of 100 by calling the my_sqrt function, passing 100 as the argument. The my_sqrt function, in turn, uses the sqrt function from the C standard library to perform the square root calculation. The result is then displayed using cout.

Question 6: What would happen if you removed the extern "C" linkage directive from the my_sqrt function?

Answer: If you removed the extern "C" linkage directive, the C++ compiler would apply name mangling to the my_sqrt function, and the function's name in the compiled code would be different. This would make it incompatible with external C functions, and you would not be able to call it from C code.*/