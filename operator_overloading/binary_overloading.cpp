//add two complex numbers
#include<iostream>
using namespace std;

class complex
{
  private: 
        int a,b;
  public:
        void set()
        {
         cout<<"\nEnter the values of a and b\n";
         cin>>a>>b;
        }
        void show()
        {
          cout<<"\na= "<<a<<" b= "<<b<<endl;
        }
    
    friend complex operator+(complex c2);
    
};

 complex operator+(complex c2)
     { 
      complex temp;
      temp.a=c2.a+a;
      temp.b=c2.b+b;
          
      return (temp);
     }



int main()
{
  complex c1,c2,c3;
  
  cout<<"\nEnter the values of first complex number\n";
  c1.set();
    cout<<"\nEnter the values of second complex number\n";
  c2.set();
  
  c3 = c2+c1;
  
  c3.show();
  
}
        
