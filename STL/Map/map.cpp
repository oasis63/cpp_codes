//c++ file handling
#include <iostream>
#include <map>
using namespace std;

int main()
{
   
  map <int,string> m1;

  cout<<" m1.empty() " << m1.empty()<<endl;

  m1[100] = "Harry";
  m1[43]  = "Potter";
  m1[678] = "Barry Allen";

  cout<<m1[100]<<endl;
  cout<<m1[43]<<endl;
  cout<<m1[678]<<endl;

  m1.insert(pair<int,string>(0,"Harish Bosak"));

  cout<<" m1.empty() " << m1.empty()<<endl;

  map <int,string>:: iterator itr = m1.begin();

  while(itr!=m1.end())
  {
  	cout<<itr->first<<" "<<itr->second<<endl;
  	itr++;
  }


}

/* Associative array */