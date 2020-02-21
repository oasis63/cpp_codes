#include<iostream>
using namespace std;


int main() 
{
    string str;
    cout<<"\nEnter a string\n";
    cin >> str;
    
    int i,n=0;
    
    while(str[n]!='\0')
      n++;
      
    for(i=0;i<n;i++)
    {
       if(str[i]=='a')
       {
         str.erase(i,1);
      
       }
    }   
  
    cout << str << endl;
}

