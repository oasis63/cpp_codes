// CPP program to find count of digits in N  
// factorial raised to N    ....   (N!)^N 
#include <bits/stdc++.h> 
using namespace std; 
  
int countDigits(int n) 
{ 
    // we take sum of logarithms as explained 
    // in the approach 
    double ans = 0; 
    for (int i = 1; i <= n; i++) 
        ans += log10(i); 
  
    // multiply the result with n 
    ans = ans * n; 
    return 1 + floor(ans); 

} 
  
int main() 
{ 
    int n = 4; 
    cout << countDigits(n) << "\n"; 
    return 0; 
}