//friend function 
#include <iostream>
using namespace std;

class Integer
{
  private: 
        int a,b;
  public:
        void set()
        {
          cout<<"\nEnter the values of a,b\n";
          cin>>a>>b;
        }
       void show()
        {
          cout<<a<<endl<<b<<endl;
        }
      friend void fun(Integer);
};
//Friend function is not a member function. So no need to give membership label (::)
void fun(Integer ob)
{
  cout<<"Sum is "<<ob.a+ob.b<<endl;
}
int main()
{
  Integer ob1;
  
  ob1.set();
  cout<<"Enter Object's data\n";
  ob1.show();
  
  fun(ob1);

  return 0;
}
         
