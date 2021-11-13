//number of repeated integers in an array
#include<iostream>
using namespace std;

int main()
{
  int n,count=1,i,j,t;
  
  cout<<"\nEnter the number of elements\n";
  cin>>n;
  
  int a[n];
  
  cout<<"\nEnter the elements\n";
  for(i=0;i<n;i++)
   cin>>a[i];
  
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
         t=a[j];
         a[j]=a[j+1];
         a[j+1]=t;
      }
    }
  }
  
  for(i=0;i<n;i++)
  {
     if(a[i]!=a[i+1] && i+1 <n)
       count++;
  }

 cout<<"\nNumber of elements "<<count<<endl;
  
}
