//reference variable
#include<iostream>
using namespace std;

int main()
{
  int a=1;
  
  int &x=a;
  
  x++;
  
  cout<<"\na="<<a<<" x="<<x<<"\n";
}
