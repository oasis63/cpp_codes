//output to a file
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
 
 fstream f;
 
 f.open("test.dat",ios::in);
 
 int n;
 
 f>>n;
 
 while(!f.eof())
 {
   cout<<n<<endl;
   f>>n;
 }
 
 f.close();
 
 return 0;
}
