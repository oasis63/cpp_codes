#include <bits/stdc++.h>
using namespace std;

// pass by reference
void swap(string& a , string& b)
{
    string temp = a;
    a=b;
    b=temp;

}

int main()
{
    string a = "Rajesh";
    string b = "coward";

   swap(a,b);

   cout<<"After Swapping the values "<<endl;

   cout<<a<<endl;
   cout<<b<<endl;

   return 0 ;
}
