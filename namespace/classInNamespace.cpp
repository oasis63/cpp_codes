//Namespace containing a class
#include<iostream>
using namespace std;

namespace ns
{

 void display();  //method declaration
 class test
 {
   public:
         void display()
         {
           cout<<"\nns::test::display()\n"<<endl;
         }
 };

}          //without semicolor (;)

void ns::display()
{
  cout<<"\nns::display()\n"<<endl;
}


int main()
{

 ns::test ob;

 ns::display();

 ob.display();


}
