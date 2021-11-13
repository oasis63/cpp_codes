#include <iostream>
using namespace std;

class A
{
  public:

   virtual void f1()
   {
     cout<<"\nIn f1 A\n";
   }

   void f2()
   {
     cout<<"\nIn f2 A\n";
   }
};

class B:public A
{
  public:
    void f1()          // Method OverRiding
    {
      cout<<"\nIn f1 B\n";
    }

    void f2(int x)    //Method Hiding
    {
      cout<<"\nIn f2 B\n";
    }


};

int main()
{

  A *p;    //pointer to the parent class
  B o;

  p=&o;   //child is being converted in the parent

  p->f1();





}

