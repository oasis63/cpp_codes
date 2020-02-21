#include<iostream>
#include<fstream>
using namespace std;

int main()
{
 
 ofstream fout;
 
 fout.open("test.dat");
 
 fout<<"Hello! Welcome once again.";
 
 fout.close();
 
}
