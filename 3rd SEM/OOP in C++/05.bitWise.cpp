/*Write a C++ Program to store two binary number in arrays and perform bitwise AND, OR and XOR operations on these two numbers.*/

#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void andOperation(int arr1[], int arr2[], int n)
{
    int result[n];
    for (int i = 0; i < n; i++)
    {
        result[i] = arr1[i] | arr2[2];
    }
    cout << "Bitwise AND: ";
    printArray(result, n);
}

void orOperation(int arr1[], int arr2[], int n)
{
    int result[n];
    for (int i = 0; i < n; i++)
    {
        result[i] = arr1[i] | arr2[i];
    }
    cout << "Bitwise OR: ";
    printArray(result, n);
}
void xorOperation(int arr1[], int arr2[], int n)
{
    int result[n];
    for (int i = 0; i < n; i++)
    {
        result[i] = arr1[i] ^ arr2[i];
    }
    cout << "Bitwise XOR: ";
    printArray(result, n);
}

int main()
{
    int n;
    cout << "Enter the number of bits: ";
    cin >> n;

    int num1[n], num2[n];
    cout << "Enter the first binary number: ";
    for (int i = 0; i < n; i++)
    {
        cin >> num1[i];
    }

    cout << "Enter the second binary number: ";
    for (int i = 0; i < n; i++)
    {
        cin >> num2[i];
    }

    cout << "Binary 1=";
    printArray(num1, n);
    cout << "Binary 2=";
    printArray(num2, n);
}

/*VIVA

Question 1: How can you relate the concept of objects to this program?

Answer: In OOP, objects are instances of classes. While this program does not explicitly define a class, you can think of the binary numbers (num1 and num2) and the results of bitwise operations (result) as data objects that encapsulate binary values. An OOP approach might involve creating a class to represent these binary numbers and encapsulate related methods.

Question 2: How could you encapsulate the binary numbers and operations in a class?

Answer: To encapsulate the binary numbers and operations in a class, you could create a BinaryNumber class. This class could have private member variables to store the binary values and public methods for performing bitwise AND, OR, and XOR operations.

cpp
Copy code
class BinaryNumber {
private:
    int* binaryArray;
    int size;

public:
    BinaryNumber(int n);
    ~BinaryNumber();
    void setBinaryValue(int binaryValue[]);
    void performAND(const BinaryNumber& other);
    void performOR(const BinaryNumber& other);
    void performXOR(const BinaryNumber& other);
    void displayBinaryValue() const;
};
Question 3: How would you use the principles of encapsulation in this program?

Answer: Encapsulation involves bundling data and the methods that operate on that data into a single unit, such as a class. In this program, you can encapsulate the binary numbers and operations within a class as mentioned in the previous answer. This way, data and operations are encapsulated together, and access to the internals can be controlled through public methods.

Question 4: Can you explain how you would use inheritance and polymorphism in this program?

Answer: While your program is relatively simple and doesn't explicitly use inheritance and polymorphism, you could extend it to include different types of binary numbers or operations. For example, you could create subclasses of BinaryNumber to represent different types of binary numbers (e.g., signed binary, two's complement) and implement polymorphic methods for performing operations.

Question 5: How would you ensure data hiding and data abstraction in an object-oriented version of this program?

Answer: Data hiding and data abstraction can be achieved by declaring the member variables of the BinaryNumber class as private and providing public methods to set values, perform operations, and display results. This way, the internal representation of binary numbers is hidden from the outside world, and users of the class interact with it through well-defined interfaces.

Question 6: Can you outline how you would implement constructors and destructors for the BinaryNumber class?

Answer: Constructors would be used to initialize a BinaryNumber object with a specified number of bits and set them to initial values. Destructors would be responsible for releasing any dynamically allocated resources, such as the binaryArray in the class. Here's a simplified example:

cpp
Copy code
BinaryNumber::BinaryNumber(int n) {
    size = n;
    binaryArray = new int[n];
    // Initialize binaryArray to a default value
}

BinaryNumber::~BinaryNumber() {
    delete[] binaryArray;
}*/