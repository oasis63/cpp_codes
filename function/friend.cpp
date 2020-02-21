#include<iostream>
using namespace std;

class test
{
  private:
    int x,y;
  public:
  
        test()  //default constructor
        {
         x=0;
         y=0;
        }
  
       test(int i,int j)  // pararmeterized constructor
       {
        
         x=i;
         y=j;
       }
       void show()
       {
         cout<<x<<endl;
         cout<<y<<endl;
       }
       
      friend void add(test a);  // friend function should be defined outside the class
       
};

void add(test a)
{
  cout<<a.x+a.y<<endl;
}

int main()
{
  test ob1(54,45);
 
  test ob3;
  
   add(ob1);
}


