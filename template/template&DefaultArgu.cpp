//Templates and Default Arguments
#include<iostream>
using namespace std;

template <class T,class U=char>
class test
{
  private:
       T x;
       U y;
  public:
       test(T a,U b)
       {
          x=a;
          y=b;
       }
       void show()
       {
          cout<<x<<endl;
          cout<<y<<endl;
       }
};

int main()
{
  test <int,char>o(4,'5');  // test <int,int>o(3,5);
  
  o.show();
} 
