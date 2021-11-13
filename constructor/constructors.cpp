//binary operator overloading of the plus sign
#include<iostream>
using namespace std;

class complex
{
 private: 
        int a,b;
 public:
      complex() //default
      {
         a=0;
         b=0;
      }
      complex(int x,int y)  //argumennt passed to the constructor
      {
        cout<<"\nInside the constructor\n";
        a=x;
        b=y;
      }
     /* void set()
      {
        cout<<"\nEnter the real and complex part\n";
        cin>>a>>b;
      }*/
      complex operator+(complex c1)
      {
        complex temp;
        temp.a=a+c1.a;
        temp.b=b+c1.b;
        return (temp);
      }
      void display();
      ~complex()
      { 
       cout<<"\nInside the constructor\n";
      } 
};
void complex::display()
{
 cout<<"The complex number after adding the given numbers \n";
 cout<<a<<"+ i"<<b<<endl;
}
int main()
{
  complex c1(4,5),c2(5,6),c3;

  c3=c2+c1;
  
  
  c3.display();
}
