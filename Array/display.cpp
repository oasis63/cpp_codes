#include<iostream>
using namespace std;

int main()
{
  int r,c,i,j;
  cout<<"\nEnter the number of rows and columns of the matrix\n";
  cin>>r>>c;
  
  int mat[r][c];
  
  cout<<"\nEnter the elements of the matrix\n";
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      cin>>mat[i][j];
    }
  }
  
  cout<<"\nEntered matrix is \n";
  
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
   
 
}
