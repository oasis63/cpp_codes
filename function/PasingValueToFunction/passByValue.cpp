#include <bits/stdc++.h>
using namespace std;

// pass by value
void swap(int a ,int b)
{
    int temp = a;
    a=b;
    b=a;

}

int main()
{

   int a = 53;
   int b= 234;

   swap(a,b);

   cout<<a<<endl;
   cout<<b<<endl;
}
