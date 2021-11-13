// C++ program to demonstrate 
// the acos() function 
#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    double result; 
    int x = -1; 

    // Function call to calculate acos(x) value 
    result = acos(x); 

    cout << "acos(-1) = " << result 
        << " radians" << endl; 
    cout << "acos(-1) = " << result * 180 / 3.141592 
        << " degrees" << endl; 

    return 0; 
} 
