#include<iostream>
#include<fstream>
using namespace std;

int main()
{
 
 
 ifstream fin;
 
 fin.open("test.dat");
 
 char ch;
 
 ch=fin.get();
 
 while(!fin.eof())   /* eof() returns 1 if file end is reached else returns  0 */
 {
   cout<<ch;
   ch=fin.get();
 }
 
 fin.close();
 
}
