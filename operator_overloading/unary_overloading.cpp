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
     complex operator-()
     { 
      complex temp;
      temp.a=-a;
      temp.b=-b;
          
      return (temp);
     }
    
};




int main()
{
  complex c1,c2,c3;
  
  cout<<"\nEnter the values of first complex number\n";
  c1.set();

  c2 = c1.operator-();
  
  cout<<"\nNegative of enterd values\n";
  
  c2.show();
  
  
  cout<<"\nUsing different method\n";
  c3 = -c1;
  
  cout<<"\nNegative of enterd values\n";
  
  c3.show();
}
        
