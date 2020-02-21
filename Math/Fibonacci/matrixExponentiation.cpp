/*

Method 4 ( Using power of the matrix {{1,1},{1,0}} )
This another O(n) which relies on the fact that if we n times multiply the matrix M = {{1,1},{1,0}} to itself 
(in other words calculate power(M, n )), 
then we get the (n+1)th Fibonacci number as the element at row and column (0, 0) in the resultant matrix.

*/



#include<bits/stdc++.h>
using namespace std;
  
/* Helper function that multiplies 2 matrices F and M of size 2*2, and 
  puts the multiplication result back to F[][] */
void multiply(int F[2][2], int M[2][2]) 
{ 
  int x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]; 
  int y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]; 
  int z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]; 
  int w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 
  
/* Helper function that calculates F[][] raise to the power n and puts the 
  result in F[][] 
  Note that this function is designed only for fib() and won't work as general 
  power function */
void power(int F[2][2], int n) 
{ 
  int i; 
  int M[2][2] = {{1,1},{1,0}}; 
  
  // n - 1 times multiply the matrix to {{1,0},{0,1}} 
  for (i = 2; i <= n; i++) 
      multiply(F, M); 
}
  
int fib(int n) 
{ 
  int F[2][2] = {{1,1},{1,0}}; 
  if (n == 0) 
      return 0; 
  power(F, n-1); 
  
  return F[0][0]; 
} 
   
  
/* Driver program to test above function */
int main() 
{ 
  for(int n=0;n<=10;n++)
    cout<<n<<" "<<fib(n)<<endl;
} 