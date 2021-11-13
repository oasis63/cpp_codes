//increment overloading 
#include<iostream>
using namespace std;

class Integer
{
  private: 
        int x;
  public:
        void set()
        {
          cout<<"\nEnter the value of x\n";
          cin>>x;
        }
       void show()
        {
          cout<<x<<endl;
        }
       Integer operator++()
       {
         Integer temp;
         temp.x = ++x;
         return(temp);
       }
       Integer operator++(int)
       {
         Integer temp;
         temp.x = x++;
         return(temp);
       }
};
int main()
{
  Integer ob1,ob2,ob3;
  
  ob1.set();
  cout<<"First Object's data\n";
  ob1.show();
  
  //Pre Increment
  ob2=++ob1;     // ob2 = ob1.operator++();
  
  
  cout<<"\nAfter Pre Incrementation\n";
  cout<<"First object \n";
  ob1.show();
  
  cout<<"Second object\n";
  ob2.show();
  
  //Post increment
  
  ob3 = ob1++;  // ob3 = ob1.operator++();
  
  
  cout<<"\nAfter Post Incrementation\n";
  cout<<"First object \n";
  ob1.show();
  
  cout<<"Third object\n";
  ob3.show();
   
  return 0;
}
         
