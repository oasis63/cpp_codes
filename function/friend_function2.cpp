#include <iostream>
using namespace std;

class B;

class A
{
  private:
    int x;
  public:
  
        A()  //default constructor
        {
         x=0;
        }
  
       A(int i)  // pararmeterized constructor
       {
        
         x=i;
       }
      friend void add(A , B);
};

class B
{
  private:
    int y;
  public:
  
        B()  //default constructor
        {
         y=0;
        }
  
       B(int i)  // pararmeterized constructor
       { 
        
         y=i;
       }
      friend void add(A , B);
};
void add(A ob1,B ob2)
{

  cout<<"Sum is "<<ob1.x+ob2.y<<endl;

}
int main()
{
  A ob1(5);
 
  B ob2(1);
  
   add(ob1,ob2);
}


