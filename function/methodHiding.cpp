#include<iostream>
using namespace std;

class A
{
  public:
  
   void f1()
   {  
     cout<<"\nIn functiona A\n";
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
  
  B o;
  
  o.f2();

}
   
