#include<bits/stdc++.h>
using namespace std;

long long int  sumOfDivisors(long long int  number,long long int  noDivisors)
{
    long long int  sum = number*(noDivisors*(noDivisors+1))/2;
    return sum;
}

int  main()
{
    long long int  t;
    cin>>t;
    
    while( t-- )
    {
        long long int  n;
        cin>>n;
        
        long long int  sum=0;
        
        long long int  noDivisors3 = (n-1)/3;
        long long int  noDivisors5 = (n-1)/5;
        long long int  noDivisors15 = (n-1)/15;
        
        sum = sumOfDivisors(5,noDivisors5) + sumOfDivisors(3,noDivisors3);
        
        sum = sum - sumOfDivisors(15,noDivisors15);
        
        cout<<sum<<endl;
    }
}