//use of templates

#include<iostream>
using namespace std;

template <typename T>    //function template
T myMax(T a,T b)
{
  return (a>b)?a:b;
}

int main()
{
  cout<<myMax<int>(6,2)<<endl;
  cout<<myMax<double>(6,9.32)<<endl;
  cout<<myMax<char>('r','d')<<endl;
  
  return 0;
}
