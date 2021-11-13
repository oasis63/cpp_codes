//dynamic allocation operators
/* new = allocating memory at runtime
  delete = deallocate memory at runtime
*/

#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
  int *p;
  
  p = new int;  // allocatin memory to the pointer
  
  cout<<"\nEnter a number\n";
  cin>>*p;
  
  cout<<*p<<endl;
  
  delete p;
  
}
