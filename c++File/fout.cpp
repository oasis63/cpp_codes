#include<iostream>
#include<fstream>
using namespace std;

int main()
{
 
 ofstream fout;
 
 fout.open("test.dat","a");
 
 fout<<"Welcome! to the programming";
 
 fout.close();
 
}
