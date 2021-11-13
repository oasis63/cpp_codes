//Namespace
#include<iostream>
using namespace std;

namespace ns
{
  int i=100;
}

int i=30;

int main()
{
  int i=23;
  
  cout<<ns::i<<endl;

}
