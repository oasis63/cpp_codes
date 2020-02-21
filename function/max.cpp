//inline function
/* the call to the function is replaced by the definition code of the function */
#include<iostream>
using namespace std;

inline void max(int a,int b)
{
  cout<<"Maximum of  the given numbers is "<<(a>b?a:b)<<endl;
}

int main()
{
  int a,b;
  cout<<"\nEnter two numbers \n";
  cin>>a>>b;
  
  max(a,b);
}
