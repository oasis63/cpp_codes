// Work always bring something. But does not contain nothig.
#include<iostream>
using namespace std;


int x=1;
int main()
{
  int x=8;
  cout<<"Main x = "<<x<<endl;
  
  cout<<"Global x = "<<::x<<endl;
  
  {
    int x=9;
    cout<<"\nInner x = "<<x<<endl;
  }
  
  cout<<"Main x = "<<x<<endl;
  
  cout<<"Global x = "<<::x<<endl;
  
  
}       

/* ::x represents the Global x
  num::x represents the x from the class */
  //inline function
/* the call to the function is replaced by the definition code of the function */
