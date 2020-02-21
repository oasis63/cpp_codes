#include<bits/stdc++.h>
using namespace std;

// GCD of two numbers with time complexity

// Euclidean Method

int gcd(int a,int b)
{
    if(a==0)
        return b;
    else
    {

        while(b!=0)
        {

            if(a>b)
                a=a-b;
            else
                b=b-a;
        }

        return a;
    }

}


int main()
{
   int a,b;

   cout<<"Enter two numbers\n";
   cin>>a>>b;

   cout<<gcd(a,b)<<endl;
}

