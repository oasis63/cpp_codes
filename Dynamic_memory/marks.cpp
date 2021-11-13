//dynamic allocation operators
/* new = allocating memory at runtime
  delete = deallocate memory at runtime
*/

// 1-D array

#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
  int *roll;
  float *marks;
  
  int size;
  
  cout<<"\nEnter the number of students\n";
  cin>>size;
  
  roll = new int[size];  // dynamically allocating memory block of size 'size'(memory for an array);
  
  marks = new float[size];
  
  for(int i=0;i<size;i++)
  {
     cout<<"\nEnter roll number and marks of "<<i+1<<" student"<<endl;
     cin>>roll[i]>>marks[i];
  }
  
  cout<<"  Roll No.\tMarks\n";
  
  for(int i=0;i<size;i++)
  {
     cout<<"  "<<roll[i]<<"\t\t"<<marks[i]<<endl;
  }
  
  delete [] roll;
  delete [] marks;
  

  
}
