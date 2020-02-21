//output to a file
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
 
 ifstream fin;
 
 fin.open("test.dat");
 
 int n;
 
    fin>>n;
 
 while(!fin.eof())
 {
   cout<<n<<endl;
   fin>>n;
 }
 
 fin.close();
 
 return 0;
}
