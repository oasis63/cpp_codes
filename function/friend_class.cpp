//friend class
#include <iostream>
using namespace std;

class B;

class A
{
  private:
        int a;
  public:
       A(int i)
       {  
       		a=i; 
       }
       
      int sum(B);
};

class B
{
  private: 
      int b;
  public:
      B(int i)
      { 
      	b=i;  
      }
      
      friend int  A::sum(B);
};

int A::sum(B ob2)
{
  return (a+ob2.b);
}
int main()
{
  A ob1(5);
  B ob2(6);
  
  int t;
  
 t=ob1.sum(ob2);
 
 cout<<t<<endl;
 
 return 0;
    
}
