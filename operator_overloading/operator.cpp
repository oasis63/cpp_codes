//operator  overloading 
#include<iostream>
using namespace std;

class threeD
{
  int x,y,z;
  
  public:
        threeD()  // default constructor
        {
           x=y=z=0;
        }
        
        threeD(int i,int j,int k)
        {
          x=i;
          y=j;
          z=k;
        }
        
        threeD operator+(threeD ob2); // declaration of operator overloading function 
        threeD operator=(threeD ob2);
        
        void show();
        
};

threeD threeD::operator+(threeD ob2)
{
  threeD ob3;
  
  ob3.x=x+ob2.x;
  ob3.y=y+ob2.y; 
  ob3.z=z+ob2.z;
 
  return ob3;
}

threeD threeD::operator=(threeD ob2)
{
  x=ob2.x;
  y=ob2.y;
  z=ob2.z;
  
  return *this;
}
void threeD::show()
{
           cout<<x<<",";
           cout<<y<<",";
           cout<<z<<endl;
}
int main()
{
  threeD a(1,2,3),b(10,10,10),c;
  
  cout<<"\nOriginal values of a: ";
  a.show();

  cout<<"\nOriginal values of b: ";
  b.show();
  
  c=a+b;
  
  cout<<"\nvalue of c after c=a+b: ";
  c.show();
  
  c=a+b+c;
  
  cout<<"\nvalue of c after c=a+b+c: ";
  c.show();
  
  c=b=a;
  
  cout<<"\nvalue of c after c=b=a: ";
  c.show();
  
  cout<<"\nvalue of b after c=b=a\n";
  
  b.show();
  
  return 0;
}
