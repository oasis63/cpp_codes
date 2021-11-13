/*Namespace containing a class declaration and definiton outside the namespace */
#include<iostream>
using namespace std;

namespace ns
{

 void display();  //method declaration
 class test;     //class declaration

}          //without semicolor (;)

class ns::test
 {
   public:
         void display()
         {
           cout<<"\nns::test::display()\n"<<endl;
         }
 };


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
