//finding the minimum in an array
#include<iostream>
using namespace std;

template <class T,int max>
T arrMin(T a[],int n)
{
  int m=max;
  
  int i;
  
  for(i=0;i<n;i++)
  {
    if(a[i] < m)
    {
      m=a[i];
    }
  }
  
  return m;
 
}

int main()
{
  
  int a[]={2,6,11,90};
  char c[]={'r','a','j','e','s','h'};
  
  cout<<arrMin<int,1000>(a,5)<<endl;
  cout<<arrMin<char,256>(c,6)<<endl;


} 
