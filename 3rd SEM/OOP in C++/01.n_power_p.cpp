/*Raising a number n to a power p is the same as multiplying n by itself p times.
Write a function called power ( ) that takes a double value for n and an int value
for p, and returns the result as double value.
Use a default argument of 2 for p, so that if this argument is omitted, the
number will be squared.
Write a main ( ) function that gets values from the user to test this function*/

#include <bits/stdc++.h>
using namespace std;

double power(double n ,  int p = 2){
    double res = 1;
    for (int i = 0; i < p; i++)
    {
        res *= n;
    }
    return res;
}


int main() {
    double n , result;
    int p;
    cout << "Enter n and p value"<<endl;
    cin >>n>>p;
    result = power(n,p);
    cout << n << " raised to power "<<p<<" is "<<result<<endl;
    result = power(n);
    cout << "By defalut argument "<< n <<" power 2 is "<<result<<endl;
    return 0;
}