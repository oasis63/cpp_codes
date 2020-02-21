// Leap year
#include<iostream>
#include<string>
using namespace std;

const char * isLeapYear(int year)
{
    // Complete this function
    if(year%400==0)
     return("Leap year");
    else if(year%100==0)
     return("Not a leap year");
    else if(year%4==0)
     return("Leap year");
    else 
     return("Not a leap year");
} 
int main()
{ 
 int y;
 cout<<"\nEnter a year\n";
 cin>>y;
 
 string s;
 
 s=isLeapYear(y);
 
 cout<<s<<endl;
}
