// C++ implementation to Divide two
// integers without using multiplication,
// division and mod operator
#include <bits/stdc++.h>
using namespace std;

// Function to divide a by b and
// return floor value of the result
long long divide2(long long dividend, long long int divisor){

    // Calculate sign of divisor i.e.,
    // sign will be negative only if
    // either one of them is negative
    // otherwise it will be positive
    long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Update both divisor and
    // dividend positive
    dividend = abs(dividend);
    divisor = abs(divisor);

    // Initialize the quotient
    long long quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }

    // Return the value of quotient with the appropriate
    // sign.
    return quotient * sign;
}


long long divide(int d2, int div2)
{

     long long dividend = long(d2);
     long long divisor = long(div2);

    // Calculate sign of divisor i.e.,
    // sign will be negative only if
    // either one of them is negative
    // otherwise it will be positive
    long long sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    // Update both divisor and
    // dividend positive
   
    dividend = abs(dividend);
    divisor = abs(divisor);

    cout<<dividend<<endl;
    cout<<divisor<<endl;

    // Initialize the quotient
    long long quotient = 0;
    while (dividend >= divisor) {
        dividend -= divisor;
        ++quotient;
    }

    // Return the value of quotient with the appropriate
    // sign.
    return quotient * sign;
}

// Driver code
int main()
{
    int a = -2147483648, b = -1;
    cout << divide(a, b) << "\n";

    a = 43, b = -8;
    cout << divide(a, b);

    return 0;
}
