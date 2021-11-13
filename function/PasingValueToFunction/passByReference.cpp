#include <bits/stdc++.h>
using namespace std;

// pass by reference
void swap(int& a ,int& b)
{
    int temp = a;
    a=b;
    b=temp;

}

int main()
{

   int a = 53;
   int b= 234;

   swap(a,b);

   cout<<"After Swapping the values "<<endl;

   cout<<a<<endl;
   cout<<b<<endl;

   return 0 ;
}
