// Work always bring something. But does not contain nothig.
//constructor and destructor
#include<iostream>
using namespace std;

class test
{
 int x;
   
  public:
    test()  //constructor
    {
      x=8;
      
      cout<<"inside the constructor\n";
    }
    void show()
    {
      cout<<"\n x= "<<x<<endl;
    }
    ~test()
    {
      cout<<"\nInside the destructor\n";
    }
};
int main()
{
  test n;

  n.show();
}
