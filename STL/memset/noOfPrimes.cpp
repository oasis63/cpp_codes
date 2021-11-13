#include <bits/stdc++.h>
using namespace std;

/* using precomputation to print the prime numbers upto the given number */

void printPrime(int n)
{
    bool prime[n+1];

    //memset(prime, true, sizeof(prime));

    for(int i=0;i<=n;i++)
    {
        prime[i] = true;
    }


    for(int i=2;i<=sqrt(n);i++)
    {
        if(prime[i] == true) // if the given numbe i is a prime
        {
            // setting the numbers which are multiple of i to false because that cannot be a prime number

            for(int p=i*2;p<=n;p+=i)
                prime[p] = false;
        }
    }

    for(int i=2;i<=n;i++)
    {
        if(prime[i])
        {
            cout<<i<<" ";
        }
    }
}

int main()
{
    int n;
    cout<<"Enter a number upto which you want to find the primes"<<endl;
    cin>>n;

    printPrime(n);

    return 0;
}
