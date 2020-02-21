// C++ program to count trailing 0s in n!
#include <iostream>
using namespace std;
 
// Function to return trailing 0s in factorial of n ... zeros at the end of the factorial 
int findTrailingZeros(int  n)
{
    // Initialize result
    int count = 0;
 
    // Keep dividing n by powers of 5 and update count
    for (int i=5; n/i>=1; i *= 5)
          count += n/i;
 
    return count;
}
 
// Driver program to test above function
int main()
{
    int n ;
    cin>>n;
    cout << "Count of trailing 0s in " << n
         << "! is " << findTrailingZeros(n)<<endl;
    return 0;
}