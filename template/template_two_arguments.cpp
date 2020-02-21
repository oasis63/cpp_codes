//When there are more than one argument
#include<iostream>
using namespace std;

template <class X,class Y>
class test
{
  private:
         X x;
         Y y;
  public:
        test(X a,Y b)
        {
          x=a;
          y=b;
        }
        
        void show()
        {
          cout<<"X = "<<x<<"\n";
          cout<<"Y = "<<y<<endl;
        }
        
        ~test()
        {
          cout<<"\nDistructing the object\n";
        }
        
};

int main()
{
  test <int,double>o(4,5.9);
  
  o.show();

}
  
