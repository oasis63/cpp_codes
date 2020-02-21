//cin as an object
#include<iostream>
using namespace std;

int main()
{
  int a;
  
  cout<<"Enter an integer\n";
  cin.operator>>(a);      // cin is an object, which calls the "operatro>>' function
  
  cout<<a<<endl;
}
        
