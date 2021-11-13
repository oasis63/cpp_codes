//using operator overloading add the threeD coordinates of tweo point
#include<iostream>
using namespace std;

class threeD
{
  private:
   int x,y,z;
  public:
    void set()
    {
      cin>>x>>y>>z;
    }
    void show()
    {  
     cout<<"The point is \n";
     cout<<x<<","<<y<<","<<z<<endl;
    }
    threeD operator+(threeD sec)
    { 
      threeD temp;
      temp.x=x+sec.x;
      temp.y=y+sec.y;
      temp.z=z+sec.z;
      
      return temp;
    }
};
int main()
{
  threeD first,secon;
  
  cout<<"\nenter the coordinates of the first point\n";
  first.set();
  
  cout<<"\nEnter the second the point\n";
  secon.set();
  
  threeD temp;
  
  
  temp=first+secon;
  
  temp.show();
}
