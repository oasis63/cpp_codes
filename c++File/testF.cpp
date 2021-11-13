//output to a file
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
 
 fstream f;
 
 f.open("num.dat",ios::out | ios::in );
 
 int i,n;
 
 cout<<"\nEnter the number of elements to be added in the file\n";
 cin>>n;
 
 for(i=0;i<n;i++)
 { 
    f<<i<<endl;
 }
 
 f>>n;
 
 while(!f.eof())
 {
   cout<<n<<endl;
   f>>n;
 }
 
 
 f.close();
 
 return 0;
}
