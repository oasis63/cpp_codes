/* Namespace 
 it is a group of declarations;
 it can be extended */

#include <iostream>
using namespace std;

namespace ms1
{
  int x;
  
  class A{
   
   public:
    void display()
    {
      cout<<"\nms1::A::display()\n";
    }
  };

}

namespace ms2
{

  using namespace ms1;
  int a,b;
  
  A obj;

}


//alias for the namespace


int main()
{
  
  ms1::x=9;
  
  ms2::obj.display();
  
  cout<<ms1::x<<endl;
    
}
  
