#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    string str; 
    cin >> str;
    
    int n=0,t;
    while(str[n]!='\0')
        n++;
    
    while(t!=n)
    {
        int i=0;
        while(str[i]!='\0')
        {
          if(str[i]==str[i+1])
           str.erase(i,2);
          i++;
        }
        t++;
    }
    
   if(str[0]=='\0')
       cout<<"Empty String"<<endl;
    else
         cout<<str<<endl;
}

