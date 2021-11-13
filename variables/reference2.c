//reference variable
#include<iostream>
using namespace std;
void func(int &x)
{
  x++;

}


int main()
{
  int a=1;
  
  func(a); 
  cout<<"\na="<<a<<"\n";
}
