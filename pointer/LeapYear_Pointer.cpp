// Leap year
#include<iostream>
#include<string>
using namespace std;

char * isLeapYear(int year)
{
    char *s[2]={"Leap year","Not a leap year"};
    
    if(year%400==0)
     return s[0];
    else if(year%100==0)
     return s[1];
    else if(year%4==0)
    return s[0];
    else 
       return s[1];
} 
int main()
{ 
 int y;
 cout<<"\nEnter a year\n";
 cin>>y;
 
 char *s;
 
 s=isLeapYear(y);
 
 cout<<s<<endl;
}
