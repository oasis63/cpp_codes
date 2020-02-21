//heap sort
#include<iostream>
using namespace std;
int heapify(int a[],int n,int i)
{
  int largest=i;
  int left=2*i+1;
  int right=2*i+2;

  if(left<n && a[left]>a[largest])
     largest=left; 

  if(right<n && a[right]>a[largest])
     largest=right;

  if(largest!=i)
  {
    swap(a[i],a[largest]);
    heapify(a,n,largest);
  }

}
int heapSort(int a[],int n)
{
  int i;
  for(i=(n/2)-1;i>=0;i--)
  {
    heapify(a,n,i);
  }

  for(i=n-1;i>=0;i--)
  {
    swap(a[0],a[i]);

    heapify(a,i,0);
  }
}
void print(int a[],int n)
{
  int i;
  for(i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main()
{
  int i,n;
  cout<<"Enter the number of elements:\n";
  cin>>n;

  int a[n];

  cout<<"Enter the elements:\n";
  for(i=0;i<n;i++)
     cin>>a[i];

  heapSort(a,n);

  print(a,n);

}
