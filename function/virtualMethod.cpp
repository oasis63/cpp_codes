// overriding gives run-time polymorphism


#include <iostream>
using namespace std;

class A
{
  public:

   virtual void f1()          // it can be overridden in the child class
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
    //B o;

  A *p = new B;    //pointer to the parent class

  //p=&o;   //child is being converted in the parent

  p->f1();

    p->f2();
}

