#include<iostream>
using namespace std;

int main()
{
  string s,b;
  
  char c;
  
  cout<<"Enter a string \n";
  cin>>s;
  
  int len=s.size();
  
  int i=0,j=len-1;
  
  while(i<j)
  {
    c=s[i];
    s[i]=s[j];
    s[j]=c;
    
    i++;
    j--;
  }
  
  
  cout<<s<<endl;
}
