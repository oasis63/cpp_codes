// Work always bring something. But does not contain nothing.
#include<iostream>
using namespace std;

class test
{
  static int x;  // declaration of the static data member
  
  public:
    void set()  //setter MUTATOR changes the values of the data members
    {
      cout<<"\nEnter the value\n";
      cin>>x;
    }
    static void show()  // static function
    {
      cout<<"\n x= "<<x<<endl;
    }
};
int test::x;  // definition of static data member

int main()
{
  test n;
  n.set();
  test::show();  // calling static function using the class-name and scope resolution
}
