//output to a file
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
 
 ofstream fout;
 
 fout.open("test.dat");
 
 int i,n;
 
 cin>>n;
 
 for(i=0;i<n;i++)
 {
   fout<<i<<" ";
 }
 
 fout.close();
 
 return 0;
}
