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
        
        complex add(complex c)
        {
          complex temp;
          temp.a=a+c.a;
          temp.b=b+c.b;
          
          return (temp);
        }
};

int main()
{
  complex c1,c2,c3;
  
  c1.set(1,2);
  c2.set(3,4);
  
  c3=c2.add(c1);
  
  c3.show();
  
}
        
