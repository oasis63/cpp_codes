//add two complex numbers
#include<iostream>
using namespace std;

class complex
{
  private: 
        int a,b;
  public:
        void set(int x,int y)
        {
          a=x;
          b=y;
        }
        void show()
        {
          cout<<"\na= "<<a<<" b= "<<b<<endl;
        }
     complex add(complex c2)
     { 
      complex temp;
      temp.a=c2.a+a;
      temp.b=c2.b+b;
          
      return (temp);
     }
    
};




int main()
{
  complex c1,c2,c3;
  
  c1.set(1,2);
  c2.set(3,4);
  
  c3=c1.add(c2);
  
  c3.show();
  
}
        
