#include<iostream>
using namespace std;

int main()
{
  double a,b;
  cin>>a;
  
  char ch;
  
  cin>>ch;
  
  switch(ch)
  {
    case '+':
            cin>>b;
            cout<<"\n="<<a+b;
            break;
    case '-':
            cin>>b;
            cout<<"\n="<<a-b;
            break;
    case '*':
            cin>>b;
            cout<<"\n="<<a*b;
            break;
    case '/':
            cin>>b;
            cout<<"\n="<<a/b;
            break;
  }
 return 0;
}
