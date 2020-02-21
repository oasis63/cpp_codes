//dynamic allocation operators
/* new = allocating memory at runtime
  delete = deallocate memory at runtime
*/

// 2-D array

#include<iostream>
using namespace std;

int main()
{
  int *mat;
  int r,c,i,j;
  cout<<"\nEnter the number of rows and columns of the matrix\n";
  cin>>r>>c;
  
  mat = new int[r*c];
  
  cout<<"\nEnter the elements of the matrix\n";
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      cin>>mat[i*c+j];
    }
  }
  
  cout<<"\nEntered matrix is \n";
  
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      cout<<mat[i*c+j]<<" ";
    }
    cout<<endl;
  }
   
 
  delete [] mat;
}
